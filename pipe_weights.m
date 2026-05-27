 
w = 4;         						 % convolution kernel width, in grid units
alpha = 1.25;  
g = 100; %recon resolution  

Ggrid = round(alpha*g);
beta = pi*sqrt((w*w)/(alpha*alpha) * (alpha-0.5)^2 - 0.8);	    	% From Beatty et al.
 ntab = 10000;                                               % ntab+1 elements in LUT
kernr = w/(2*Ggrid);                     					% kern radius, in ksp 
dkvect = 0:kernr/ntab:kernr;                 				% has ntab+1 elements
Ktab = (Ggrid/w)*besseli(0,beta*sqrt(1-(dkvect/kernr).^2));          % kerneltable 
%------------------------------------------%
% 'normalize kernel for pipe weights...'
Ktab = mat2gray(Ktab,[0 max(Ktab)]);		% normalize kernel so that max is 1
C = getdeap(g,Ggrid,w,beta); 	% generate deapodization function

niter = 100;
    W1 = ones(size(real(klocs)));		% for 0th iteration of weights
   
    for iter = 1:niter
    
           % W1 = previous
           % W2 = new
           
%         'writing input files...'
        fn_kx = 'INPUT_kx'; 
        fn_ky = 'INPUT_ky'; 
        fn_wcol = 'INPUT_wcol'; 
        fn_datr = 'INPUT_datr'; 
        fn_dati = 'INPUT_dati'; 
        fn_ktab = 'INPUT_ktab'; 
        fn_conf = 'INPUT_conf'; 
        fn_outr = 'OUTPUT_outr'; 
        fn_outi = 'OUTPUT_outi'; 
	
        fid_kx = fopen(fn_kx,'wb','l'); 
        fid_ky = fopen(fn_ky,'wb','l'); 
        fid_wcol = fopen(fn_wcol,'wb','l'); 
        fid_ktab = fopen(fn_ktab,'wb','l'); 
        fid_datr = fopen(fn_datr,'wb','l'); 
        fid_dati = fopen(fn_dati,'wb','l'); 
        fid_conf = fopen(fn_conf,'wb','l'); 
	
        fwrite(fid_ktab, Ktab,'float'); 
        nsamples = length(Kdatcol);  
        fwrite(fid_conf, [Ggrid nsamples ntab w],'float');
        fwrite(fid_kx, real(klocs),'float'); 
        fwrite(fid_ky, imag(klocs),'float');
        fwrite(fid_wcol, W1,'float'); 
        fwrite(fid_datr, real(Kdatcol),'float'); 
        fwrite(fid_dati, imag(Kdatcol),'float');
        fclose('all');

        !get_pipe_weights2d

%         'read weight...'
        fn_wcol2 = 'OUTPUT_wcol2'; 
        fid_wcol2 = fopen(fn_wcol2,'rb','l');
        Wtemp = fread(fid_wcol2, [nsamples], 'float');
        W2 = W1./Wtemp;     % new weights = old weights./get_pipe_weights2d outcome
        W1 = W2;
        
    end

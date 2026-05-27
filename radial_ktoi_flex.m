%GL hack of a hack

% % radial_ktoi.m

% basic regridding of radial kspace data to Cartesian image space, from
% Rachel's code

% Helen Marshall, 17 Jun 2009
% -------------------------------------

% takes in ksp raw data (kspace) and current image estimate (x)


% % ***********************************************************
% % SYSTEM MATRIX A TO GO FROM CURRENT IMAGE (X) TO KSPACE
% % *coil, deapodise, ifft, interpolate (Cartesian to radial)
% % ***********************************************************


nslice = 1;
xres = 256;     % number of samples in a projection
nproj = 50;   % number of projections
kwidth = 100;   % reconstruction resolution (G,G) - this should equal to nfreq of scan
G = kwidth;

w = 4;         						 % convolution kernel width, in grid units
alpha = 1.25;  
Ggrid = round(alpha*G);
g = G;  
beta = pi*sqrt((w*w)/(alpha*alpha) * (alpha-0.5)^2 - 0.8);	    	% From Beatty et al.
%------------ generate LUT ----------------%
ntab = 10000;                                               % ntab+1 elements in LUT
kernr = w/(2*Ggrid);                     					% kern radius, in ksp 
dkvect = 0:kernr/ntab:kernr;                 				% has ntab+1 elements
Ktab = (Ggrid/w)*besseli(0,beta*sqrt(1-(dkvect/kernr).^2));          % kerneltable 
%------------------------------------------%
% 'normalize kernel for pipe weights...'
Ktab = mat2gray(Ktab,[0 max(Ktab)]);		% normalize kernel so that max is 1
C = getdeap(G,Ggrid,w,beta); 	% generate deapodization function
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%GL Removed this entire section
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% % do gridding slice by slice
% % ksp = zeros(Ggrid, Ggrid, nslice);
% load('ksp1')
% 
% first = 1;   % start of contrast uptake
% 
% % split up whole acquisition of sequential projections into multiple sets of nproj (05/10/09), starting from first contrast uptake
% nproj_tot = 1980-first;
% nsets = floor(nproj_tot./nproj);
% windows = zeros(xres,nproj,nsets);
% for i = 1:1:nsets
%     windows(:,:,i) = time_domain(:,((i-1)*nproj)+first:((i-1)*nproj)+first+nproj-1);
% end
% 
% cnt = first             % counter for projections (start at 1st projection with signal)
% for set = 1:1:nsets
% %     for set = 1:1:6
%     time_domain = squeeze(windows(:,:,set));
% 
%     kspace = reshape(time_domain, xres.*nproj, 1);
%     for s = 1:nslice
%         disp(['s = ' num2str(s)]);
%         offset = 1;
%         cnt
%         [kx1,ky1] = gridmapf(1,1,1,nproj,kwidth,offset,cnt);
% %         [kx1,ky1] = gridmapf_cal(1,1,1,nproj,kwidth,offset,0);
%   
%         kx1 = kx1';  
%         ky1 = ky1';
%         X = kx1(:);         % columns
%         Y = ky1(:);  
%         
%          % can use to see how projections fill plane
% %          for i = 1:nproj
% %            figure(1); plot(kx1(:,i),ky1(:,i),'.b'); 
% %            pause(2)
% %            hold on; 
% %          end
%                
%         xdim = kwidth; 
%         ydim = kwidth; 
%         klocs = complex(X/G, Y/G);  % k-space locations
% 
%         Kdatcol = kspace(:,s);         % Ax-y having A' applied to it
% 
%     % use DCF from Jim's program instead of Pipe weights
% %     load('DCF')
%     % make DCF for 128 data
%         DCF = zeros(size(time_domain,1),1); 
%         coords_centred = 1:xres;
%         pk = (xres./2)+1;
%         for r = 1:size(time_domain,1)
%             DCF(r) = abs(coords_centred(r)-pk); 
%         end
%         DCF(pk) = 0.25;
%         DCF = DCF/nproj;% normalise by n_angles 
%     
%         W = ones(size(real(klocs)));
%         for ind = 1:xres:size(real(klocs))
%             W(ind:ind+(xres-1)) = DCF(:);
%         end
%         return
%    
% %     % simple compensation for decay of magnetisation over time: 
% %     decay = zeros(nproj,1);
% %     for proj = 1:nproj
% %         decay(proj) = max(abs(time_domain(:,proj)));  % take max of echo
% % %         decay(proj) = abs(time_domain(129, proj));      % use point 129 (max for most)
% %     end
%    
% %     % polynomial fit to decay to reduce effects of noise (added 06/07/09)
% %     x = zeros(nproj,1);
% %     for proj = 1:nproj
% %         x(proj) = proj;
% %     end
% %     param = polyfit(x,decay,3);     % 3rd order polynomial fit to data
% %     fit = polyval(param,x);
% %     comp_func = min(fit)./fit;  % using fitted k=0 data
%     
% % %     load('zeroth')
% % %     decay = zeroth;
% % 
% % %     comp_func = min(decay)./decay;  % used prior to 06/07/09
% %     comp = zeros(xres.*nproj, 1);
% % %     vals = ones(32,1).*comp_func(100);
% %     for n = 1:xres:xres.*nproj
% %         comp(n:n+(xres-1)) = comp_func(1+((n-1)./xres));
% % %         comp(n:n+(xres-1)) = fit(1+((n-1)./xres));  % to look at effect of filter in image space (16/07/09)
% % %         % if want to introduce adaptive filter in kr for higher projection numbers (07/07/09)
% % %         if n > xres.*100        % if higher than the 100th projection
% % %             comp(n:n+31) = vals;
% % %             comp(n+224:n+255) = vals;
% % %         end
% % %         % end of adaptive filter in kr
% %     end
%  
% %     Kdatcol = Kdatcol.*comp;
% 
% %     Kdatcol = comp;  % to look at effect of filter in image space (16/07/09)
%     % end compensation for decay of magnetisation over time
%     
%     
% %     % GET PIPE WEIGHTS using c++ code get_pipe_weights_2D
% %     niter = 6;
% %     W1 = ones(size(real(klocs)));		% for 0th iteration of weights
% %    
% %     for iter = 1:niter
% %     
% %            % W1 = previous
% %            % W2 = new
% %            
% % %         'writing input files...'
% %         fn_kx = 'INPUT_kx'; 
% %         fn_ky = 'INPUT_ky'; 
% %         fn_wcol = 'INPUT_wcol'; 
% %         fn_datr = 'INPUT_datr'; 
% %         fn_dati = 'INPUT_dati'; 
% %         fn_ktab = 'INPUT_ktab'; 
% %         fn_conf = 'INPUT_conf'; 
% %         fn_outr = 'OUTPUT_outr'; 
% %         fn_outi = 'OUTPUT_outi'; 
% % 	
% %         fid_kx = fopen(fn_kx,'wb','l'); 
% %         fid_ky = fopen(fn_ky,'wb','l'); 
% %         fid_wcol = fopen(fn_wcol,'wb','l'); 
% %         fid_ktab = fopen(fn_ktab,'wb','l'); 
% %         fid_datr = fopen(fn_datr,'wb','l'); 
% %         fid_dati = fopen(fn_dati,'wb','l'); 
% %         fid_conf = fopen(fn_conf,'wb','l'); 
% % 	
% %         fwrite(fid_ktab, Ktab,'float'); 
% %         nsamples = length(Kdatcol);  
% %         fwrite(fid_conf, [Ggrid nsamples ntab w],'float');
% %         fwrite(fid_kx, real(klocs),'float'); 
% %         fwrite(fid_ky, imag(klocs),'float');
% %         fwrite(fid_wcol, W1,'float'); 
% %         fwrite(fid_datr, real(Kdatcol),'float'); 
% %         fwrite(fid_dati, imag(Kdatcol),'float');
% % 
% %         !get_pipe_weights2d
% % 
% % %         'read weight...'
% %         fn_wcol2 = 'OUTPUT_wcol2'; 
% %         fid_wcol2 = fopen(fn_wcol2,'rb','l');
% %         Wtemp = fread(fid_wcol2, [nsamples], 'float');
% %         W2 = W1./Wtemp;     % new weights = old weights./get_pipe_weights2d outcome
% %         W1 = W2;
% %         
% %     end
% %     
% %     
% %     % include for 256 samples only
% %     ww = reshape(W1, xres, nproj);
% %     ww(1,:) = 0;        % zero beginning and end weights
% %     ww(end,:) = 0;
% %     W1 = ww(:); clear ww;
% %     % -------------------
% %     
% %     W = W1;
% % %     weights(:,s) = W;
% 
%     % % regridding from klocs (intended kspace locations) to Cartesian grid
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

    % klocs, W and Kdatcol must be vectors where elements match between the
    % three, apart from that order input doesn't matter.
	fwrite(fid_kx, real(klocs),'float');        % kx locations  (xres*nproj)
	fwrite(fid_ky, imag(klocs),'float');        % ky locations
	fwrite(fid_wcol, W,'float');                % weights       (xres*nproj)
	fwrite(fid_ktab, Ktab,'float');             % half of gridding kernel
	fwrite(fid_datr, real(Kdatcol),'float');    % real k-space data
	fwrite(fid_dati, imag(Kdatcol),'float');    % imag k-space data
	nsamples = length(Kdatcol);                 
	fwrite(fid_conf, [Ggrid nsamples ntab w],'float');      % 'config' file with some parameters 
	fclose('all');
 		
	% calls executable -- must be in directory, must have executable permissions by user
% 	tic
		!regcpp2D			
% 	toc

% 	'read outputs...'
	fid_outr = fopen(fn_outr,'rb','l');			% little endian 
	fid_outi = fopen(fn_outi,'rb','l');
	gr = fread(fid_outr, [Ggrid, Ggrid], 'float');	
	gi = fread(fid_outi, [Ggrid, Ggrid], 'float');
	gridded = complex(gr, gi); 
  %  ksp(:,:,s) = gridded;
    % --------------------------------- end regridding
    
%end %% end slice loop

% clear Ktab W alpha beta dkvect g gi gr kernr kk kwidth ntab w
% clear Kdatcol gridded klocs res weights
imshow(abs(gridded),[0 20])
imtemp = fftshift(ifftn(fftshift(gridded)));  
% % clear ksp
% for s = 1:nslice
%     im(:,:,s) = imtemp(:,:,s)./C;
% end
% % clear C imtemp

% figure
% % imagesc(abs(im(Ggrid/2-((xres./4)-1):Ggrid/2+1+((xres./4)-1),Ggrid/2-((xres./4)-1):Ggrid/2+1+((xres./4)-1)))); axis image; axis off; colormap('gray');
% imagesc(abs(im(Ggrid/2-((xres./2)-1):Ggrid/2+1+((xres./2)-1),Ggrid/2-((xres./2)-1):Ggrid/2+1+((xres./2)-1)))); axis image; axis off; colormap('gray');
% 
% savename = ['im_' num2str(set) '.mat']; 
% save(savename, 'im');
% 
% cnt = cnt + nproj;
% 
% end         % end of set loop
% 
% return
% 
% for d = 1:9
%     load(['im_' num2str(d)]);
%     subplot(3,3,d); imagesc(abs(flipud(rot90(im)))); axis off; axis image; colormap('gray');
% end
% 
% for d = 1:3
%     load(['im_' num2str(d)]);
%     subplot(1,3,d); imagesc(abs(flipud(rot90(im)))); axis off; axis image; colormap('gray');
% end




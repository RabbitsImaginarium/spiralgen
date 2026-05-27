%GL hack, 120502
%rewrote the file output to a mex function
% % radial_ktoi.m

% basic regridding of radial kspace data to Cartesian image space, from
% Rachel's code

% Helen Marshall, 17 Jun 2009
% -------------------------------------


% takes in ksp raw data (kspace) and current image estimate (x)



function [gridded img W1] = regrid(traj, data, imsize, W1,fshift,srate,lb,scale)
%W1 is either the weight or the number of iterations
%assume that traj is in GL format which is [kx+i*ky, #arms/projections/iterations]

%Added a call to demodulate (in Hz)
%and linebroad (in Random)

%truncate to the minimum of either number of data points or trajectory points
[a b] = size(data);
[c d] = size(traj);
a = min(a,c);
b = min(b,d);
traj = traj(1:a,1:b);
data = data(1:a,1:b);

%correctly scale trajectory 
m = max(abs(traj(:)));
if(exist('scale','var')>0)
    if scale<2;
        scale = 2; %at most 0.5 to -0.5
    else
        scale = 2*scale;
    end
else
    scale=2;
end

klocs = traj(:)./(scale*m);

if(exist('fshift','var')>0)
    if(exist('srate','var')==0)
        srate=62500;
    end
    data = demod(data,fshift,srate);
end
if(exist('lb','var')>0)
    data = linebroad(data,lb)';
end

%some housekeeping to keep variable names similar
Kdatcol=data(:);
kwidth = imsize;
G = kwidth;
w =4;         						 % convolution kernel width, in grid units
alpha = 1.25;
Ggrid = round(alpha*G);
beta = pi*sqrt((w*w)/(alpha*alpha) * (alpha-0.5)^2 - 0.8);	    	% From Beatty et al.
%------------ generate LUT ----------------%
ntab = 10000;                                               % ntab+1 elements in LUT
kernr = w/(2*Ggrid);                     					% kern radius, in ksp
dkvect = 0:kernr/ntab:kernr;                 				% has ntab+1 elements
Ktab = (Ggrid/w)*besseli(0,beta*sqrt(1-(dkvect/kernr).^2));          % kerneltable
%------------------------------------------%
% 'normalize kernel for pipe weights...'
%mod on121104 Ktab = mat2gray(Ktab);		% normalize kernel so that max is 1
Ktab=Ktab./max(Ktab);
nsamples = length(Kdatcol);
%130204 - deapodization kernel, need to make this circularly symmetric
%Ktab2 = [Ktab(1:floor((ntab+1)/w)+1:ntab+1)';zeros(Ggrid/2-w,1)];
%Deap = (fftshift(fft([flipud(Ktab2); Ktab2])));
%Deap = sqrt((Deap*ones(1,Ggrid)).*(Deap*ones(1,Ggrid))');

if(nargin<4)
    pipe_weight=1;
else
    if(length(W1)==1)
        niter=W1;
        pipe_weight=1;
    else
        pipe_weight=0;
        W1 = W1(1:a*b);
    end
end

if(pipe_weight)
    disp('Generating Trajectory Weight');
    W1 = ones(size(real(klocs)));		% for 0th iteration of weights
    for iter = 1:niter
        [Wtemp] = mexpipe([Ggrid nsamples ntab w], real(klocs), imag(klocs), W1,Ktab);
        W1 = W1./Wtemp;
        clear mex; %deal with this memory leak
    end
end


% klocs, W and Kdatcol must be vectors where elements match between the
% three, apart from that order input doesn't matter.
% Make the action happen
[gr, gi] = mexreg([Ggrid nsamples ntab w], real(klocs), imag(klocs), W1, real(Kdatcol), imag(Kdatcol),Ktab);
gridded = (reshape(gr, Ggrid, Ggrid)+1i*reshape(gi, Ggrid, Ggrid));
img = fftshift(ifftn(fftshift(gridded)));

%[gr, gi] = mexreg([Ggrid nsamples ntab w], real(klocs), imag(klocs), W1, real(Kdatcol), imag(Kdatcol),Ktab);
%gridded = (reshape(gr, Ggrid, Ggrid)+1i*reshape(gi, Ggrid, Ggrid));
%img = fftshift(ifftn(fftshift(gridded)));


clear mex;


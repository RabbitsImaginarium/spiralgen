%GL hack
%rewrote the file output to a mex function
% % radial_ktoi.m

% basic regridding of radial kspace data to Cartesian image space, from
% Rachel's code

% Helen Marshall, 17 Jun 2009
% -------------------------------------


% takes in ksp raw data (kspace) and current image estimate (x)



function [gridded psf kw] = regrid(traj, data, imsize,div)
%W1 is either the weight or the number of iterations
%assume that traj is in GL format
%cuz I is laZ
[a b] = size(data);
[c d] = size(traj);
a = min(a,c);
b = min(b,d);
traj = traj(1:a,1:b);
data = data(1:a,1:b);
m = max(abs(traj(:)));
klocs = traj(:)./(div*m); %normalize over 0.5: -0.5
Kdatcol=data(:);
if nargin< 3
    kwidth = 80;   % reconstruction resolution (G,G) - this should equal to nfreq of scan
else
    kwidth = imsize;
end
G = kwidth;

w = 4;         						 % convolution kernel width, in grid units
alpha = 1.1;
Ggrid = round(alpha*G);
beta = pi*sqrt((w*w)/(alpha*alpha) * (alpha-0.5)^2 - 0.8);	    	% From Beatty et al.
%------------ generate LUT ----------------%
ntab = 10000;                                               % ntab+1 elements in LUT
kernr = w/(2*Ggrid);                     					% kern radius, in ksp
dkvect = 0:kernr/ntab:kernr;                 				% has ntab+1 elements
Ktab = (Ggrid/w)*besseli(0,beta*sqrt(1-(dkvect/kernr).^2));          % kerneltable
%------------------------------------------%
% 'normalize kernel for pipe weights...'
Ktab = mat2gray(Ktab,[0 max(Ktab)]);		% normalize kernel so that max is 1
nsamples = length(Kdatcol);
%C = getdeap(G,Ggrid,w,beta); 	% generate deapodization function
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% if(nargin<4)
%     pipe_weight=1;
% else
%     if(length(W1)==1)
%         niter=W1;
%         pipe_weight=1;
%     else
%         pipe_weight=0;
%         W1 = W1(1:a*b);
%     end
% end
% if(pipe_weight)
%     figure(100)
%     clf
%     hold on
%     W1 = ones(size(real(klocs)));		% for 0th iteration of weights
%     for iter = 1:niter
%         [Wtemp] = mexpipe([Ggrid nsamples ntab w], real(klocs), imag(klocs), W1,Ktab);
%         W1 = W1./Wtemp;
%         plot(W1(1:2048));pause(0.001);
%     end
% end

% klocs, W and Kdatcol must be vectors where elements match between the
% three, apart from that order input doesn't matter.
%Makes the action happen
%get the weight function
[wr, wi] = mexreg([Ggrid nsamples ntab w], real(klocs), imag(klocs), ones(length(klocs),1), ones(length(klocs),1), zeros(length(klocs),1),Ktab);
kw = reshape(wr+1i.*wi,Ggrid, Ggrid);
kw(kw<1)=1; %eliminates the zero=NAN divisions
[gr, gi] = mexreg([Ggrid nsamples ntab w], real(klocs), imag(klocs),  ones(length(klocs),1), real(Kdatcol), imag(Kdatcol),Ktab);
gr = reshape(gr, Ggrid, Ggrid);
gi = reshape(gi, Ggrid, Ggrid);
gridded = (gr+1i*gi);
figure(1)
clf
imagesc(log(abs(gridded)))
title('log abs gridded');
figure(2)
clf
psf = fftshift(ifft2(gridded));
imagesc(log(abs(gridded./kw)));
title('log abs corrected');
figure(3);
clf
imagesc(log(abs(kw)));
title('log abs weight');


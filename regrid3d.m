%GL hack, 120502
%rewrote the file output to a mex function
% % radial_ktoi.m

% basic regridding of radial kspace data to Cartesian image space, from
% Rachel's code

% Helen Marshall, 17 Jun 2009
% -------------------------------------


% takes in ksp raw data (kspace) and current image estimate (x)



function [gridded img W1] = regrid3d(traj, zlocs, data, imsize, num_zlocs, W1,scale)
%W1 is either the weight or the number of iterations
%assume that traj is in GL format which is [kx+i*ky, #arms/projections/iterations]
%assume that 3d traj is [kx+i*ky

%truncate to the minimum of either number of data points or trajectory poitns
[a b] = size(data);
[c d] = size(traj);
%zlocs should be the same length as traj because each x & y element have to
%have a z co-ordinate

a = min(a,c);
b = min(b,d);
traj = traj(1:a,1:b);
zlocs=zlocs(1:a,1:b);
data = data(1:a,1:b);

%correctly scale trajectory
m = max(abs(traj(:)));
if scale<1;
    scale = 2; %at most 0.5 to -0.5
else
    scale = 2*scale;
end
klocs = traj(:)./(scale*m);
zlocs= zlocs(:)./(scale*m);


%some housekeeping to keep variable names similar
Kdatcol=data(:);
kwidth = imsize;
G = kwidth;
w = 4;         						 % convolution kernel width, in grid units
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
    disp('Computing Trajectory Weight');
    W1 = ones(size(klocs));		% for 0th iteration of weights
    for iter = 1:niter
        [Wtemp ]=mexreg3D([Ggrid num_zlocs nsamples ntab w], real(klocs), imag(klocs), zlocs, W1, ones(size(zlocs)), zeros(size(zlocs)),Ktab);
        %        [Wtemp] = mexpipe3D([Ggrid num_zlocs nsamples ntab w], real(klocs), imag(klocs), zlocs, W1,Ktab);
        count=1;
        tmp = zeros(Ggrid, Ggrid, num_zlocs);
        for x=1:Ggrid
            for y=1:Ggrid
                for z=1:num_zlocs
                    tmp(x,y,z) = Wtemp(count);
                    count=count+1;
                end
            end
        end
        %Wtemp2=imresize(tmp,[Ggrid Ggrid num_zlocs]);
        Wtemp2 = interp1(0:1/(length(Wtemp)-1):1, Wtemp, 0:1/(length(W1)-1):1);
        Wtemp2(Wtemp2<1)=1;
        W1 = W1./Wtemp2';
        clear mex; %deal with this memory leak
    end
end

%Frequency Correction term
%S(t) = e(i2pi*fo*t)*INT(M(x,y)*e(i*2pi[kx+dkx)x+(ky+dky)y])dxdy
%

% klocs, W and Kdatcol must be vectors where elements match between the
% three, apart from that order input doesn't matter.
% Make the action happen
[gr, gi] = mexreg3D([Ggrid num_zlocs nsamples ntab w], real(klocs), imag(klocs), zlocs, W1, real(Kdatcol), imag(Kdatcol),Ktab);

% 
% 
% outr = zeros(Ggrid, Ggrid, num_zlocs);
% outi = zeros(Ggrid, Ggrid, num_zlocs);f
% ky = imag(klocs);
% kz = zlocs;
% zlocations = num_zlocs;
% gridcenter = Ggrid/2;
% gridcenterz = num_zlocs/2;
% for kcount=1:nsamples;%(int kcount = 0; kcount < nsamples; kcount++) {
%     ixmin =  floor(kx(kcount)*Ggrid + gridcenter - w/2) - 1;
%     iymin =  floor(ky(kcount)*Ggrid + gridcenter - w/2) - 1;
%     ixmax =  ceil(kx(kcount)*Ggrid + gridcenter + w/2) - 1;
%     iymax =  ceil(ky(kcount)*Ggrid + gridcenter + w/2) - 1;
%     izmin =  floor(kz(kcount)*zlocations + gridcenterz ) ;
%     izmax =  ceil(kz(kcount)*zlocations + gridcenterz ) ;
%     
%     %       //printf("kz[kcount]=%f izmin=%i izmax=%i\n", kz[kcount], zlocations, gridcenterz, izmin, izmax);
%     
%     if (ixmin < 0)
%         ixmin = 0;
%     end
%     if (iymin < 0)
%         iymin = 0;
%     end
%     if (ixmax > Ggrid-1)
%         ixmax = Ggrid - 1;
%     end
%     if (iymax > Ggrid-1)
%         iymax = Ggrid - 1;
%     end
%     if (izmin < 0)
%         izmin = 0;
%     end
%     if (izmax > zlocations-1)
%         izmax = zlocations - 1;
%     end
%     
%     for h = ixmin:ixmax
%         dkx = (h-gridcenter) / Ggrid - kx(kcount);
%         for j = iymin:iymax
%             dky = (j-gridcenter) / Ggrid - ky(kcount);
%             for k = izmin:izmax
%                 dkz = (k-gridcenterz)/ zlocations - kz(kcount);
%                 
%                 
%                 dk = sqrt(dkx*dkx + dky*dky + dkz*dkz);% //check that this is true
%                 %printf("izmin=%i, izmax=%i, dk=%f, kzcount=%f\n ", izmin, izmax,dk, kz[kcount]);
%                 %fflush(stdout);
%                 
%                 if (dk <= kernr)
%                     %                      //  printf("\n");
%                     fracdk = dk/kernr;
%                     pos = fracdk*ntab;
%                     ind1 = floor(pos);
%                     ind2 = ceil(pos);
%                     fracpos = pos - ind1;
%                     
%                     kernvalue = Ktab(ind1) - fracpos*(Ktab(ind1) - Ktab(ind2));
%                     outr(h,j,k) = outr(h,j,k) + kernvalue;%*datwtr[kcount];
%                     outi(h,j,k) = outi(h,j,k) + kernvalue;%*datwti[kcount];
%                 end%}  /* dk <= kernr */
%             end%}/*k loop*/
%         end%}  /* j loop */
%     end%}  /* i loop */
% end%}  /* kcount */
% 
% 




tmp = reshape(gr,num_zlocs,Ggrid,Ggrid)+1i*reshape(gi,num_zlocs,Ggrid,Ggrid);

%count = 1;
%tmp = zeros(Ggrid, Ggrid, num_zlocs);
%for x=1:Ggrid
%    disp(num2str(x));
%    for y=1:Ggrid
%        for z=1:num_zlocs
%            tmp(x,y,z) = gr(count)+1i*gi(count);
%            count=count+1;
%        end
%    end
%end
%figure(1);imagesc(abs(tmp(:,:,1)));
%figure(2);imagesc(abs(tmp(:,:,2)));
%reshape don't do diddly
%gridded = (reshape(gr, Ggrid, Ggrid,num_zlocs)+1i*reshape(gi, Ggrid, Ggrid,num_zlocs));
gridded=permute(tmp,[2 3 1]);
img = 0;
%img = fftshift(ifftn(fftshift(gridded)));
clear mex;


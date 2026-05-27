
function [kxil,kyil] = gridmapf(num_il,num_dith,dith_index,num_proj,nr,offset,theta0)

%num_il = ninterl
%num_dith = ndith
%dith_index = dg
%num_proj = nproj
%nr = kwidth
%offset
%theta0);


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%calculate angles
% num_proj = 201;                 %only for SEQUENTIAL acquired with 201 projections
angle=zeros(num_proj,num_dith);
st_theta=(theta0-1)*(pi/num_proj);  % start angle for SEQUENTIAL
% st_theta = (theta0-1)*1.9416;   % find start angle for this set of projections - GOLDEN, 3T
% st_theta = (theta0)*1.9416;   % find start angle for this set of projections - GOLDEN, 1.5T
for j=1:1:num_dith                  % store in all the angles
for m=1:1:num_proj
	delta_theta = pi/num_proj;  % SEQUENTIAL
%     delta_theta = 1.9416;      % golden angle in radians, HM 03/08/09 - GOLDEN
	angle(m,j) = delta_theta*(j-1)/num_dith + (m-1)*delta_theta + st_theta;
end	      
end

% % original code for normal case
% angle=zeros(num_proj,num_dith);
% st_theta=(theta0*pi)/180;
% for j=1:1:num_dith                  % store in all the angles
% for m=1:1:num_proj
% 	delta_theta = pi/num_proj;
% %     delta_theta = 1.9416;
% 	angle(m,j) = delta_theta*(j-1)/num_dith + (m-1)*delta_theta + st_theta;
% end	      
% end


%figure; imagesc(angle); 

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%calculate axis vector

for i=1:1:nr
    ax(i) = i - offset - nr/2;    % maybe should be i-1?
end
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%calculate PR kspace grid points using 2d angle array

kx=zeros(num_proj,nr);
ky=zeros(num_proj,nr);
  
for j1=1:1:num_proj 
for i1=1:1:nr
%for m1=1:1:num_dith 

	kx(j1,i1) = cos(angle(j1,dith_index)) * ax(i1);
	ky(j1,i1) = sin(angle(j1,dith_index)) * ax(i1);
%end
end
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%% Do interleave sort on 3d kx,ky

% num_il=4;

for j1=1:num_proj
n=rem((j1-1),num_il);
kxil(((((j1-1)-n)/num_il)+n*num_proj/num_il+1),:)=kx(j1,:);
kyil(((((j1-1)-n)/num_il)+n*num_proj/num_il+1),:)=ky(j1,:);
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

        %for i = 1:nproj
        %   figure(1); plot(kxil(i,:),kyil(i,:),'.b'); 
        %   pause(0.1)
        %   hold on; 
        %end


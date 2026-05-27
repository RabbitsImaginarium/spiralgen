%Spiral Gen wrapper function
%Underlying wave writing code cribbed from HM
%updated 121023, removed nucleus 
%with safety and npartitions
%120420
%  HM 18/02/10
%  make 129Xe waveform 16/09/11
function [traj2 klocs] = spiralgen(xres, yres, fov, safety, npartitions,nucleus)


if(exist('xres','var')==0)
    xres = 512; %points
end
if(exist('yres','var')==0)
    yres = 80; %arms
end
if(exist('fov','var')==0)
    fov = 0.4; %fov in m
end
if(exist('rbw','var')==0)
    rbw =250000;%125000;%125000;%62500;%changing for low bandwidth spirals GL130104 250000; %bandwidth in kHz
end
if(exist('smax','var')==0)
    smax = 110/3;%110; %mT/m/s
end
if(exist('gmax','var')==0)
    gmax = 10e-3;%30e-3;%temporary for helium33e-3; %mT/m
end
if(exist('k_a','var') ==0)
    k_a = 100;
end
if(exist('k_b','var')==0)
    k_b = 100;
end
if(exist('density','var')==0)
    density=1.0;
end
if(exist('nucleus','var')==0)
    nucleus =1;%
end
if(exist('rhimsize','var')==0)
    rhimsize=128;
end
if(exist('b0mapdelay','var')==0)
    b0mapdelay =0; %flag to generate b0 maps in the trajectories
end
%120814 partition the trajectory acquisition time
if(exist('npartitions','var')==0)
    npartitions=4; 
end

%stupid safety
if(exist('safety','var')==0)
safety = 0.9; %safety factor
end

[a, b]=mexspiral([xres yres 1000*fov rbw/1000 safety*smax/10 safety*gmax*100 k_a k_b density nucleus rhimsize]);
traj = safety*gmax*(a+1i*b); %normalized to gmax

% gamma=2.68e8;       % for proton in rad/s/Tesla
% gamma=2.03575204e8;       % for 3He in rad/s/Tesla (32.4MHz/T*2pi)
%gamma=0.74e8          % for 129Xe in rad/s/Tesla (11.77MHz/T*2pi)

traj2 = rampdown(traj(:,1));
%rotate for complete trajectory
%golden 111.246 OR 360/yres
ang=360/yres;
%ang = 111.246;
for p =2:yres
    traj2(:,p) = rottraj(traj2(:,1),(p-1)*ang);
end
%npartitions=4;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%partition the spiral acquisition
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
if(npartitions>0) %for spirals pre npartitions addition
    nsteps = floor(yres/npartitions);
    count=1;
    traj3 = zeros(size(traj2));
    for p = 0:nsteps-1
        for q = 0:npartitions-1
            %traj3(:,count) = traj2(:,p+q*npartitions);
            traj3(:,count) = traj2(:,p+q*nsteps+1);
            %bins(count) = p+q*nsteps+1;
            count=count+1;
        end       
    end
    traj2 = traj3;
end
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%shove a spectral acquisition in here as well
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%traj3(:,count) = zeros(size(traj3(:,count-1)));
%yres=yres+1;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%removed this bit because the code naturally does this
%for nacquisitions > ninterleaves 121015
%Repeat spiral n times
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%count=1;
%for p = 1:nreps
%    for q=1:yres
%        traj4(:,count) = traj3(:,q);
%        count=count+1;
%    end
%end
%yres=yres*nreps;
        
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%set it to output%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


if(b0mapdelay>0) %single shot spiral with lower xres
    %b0mapdelay is in microseconds (ms before 120517) assume that we are sampling at 250khz so one point
    %every 4 us
    b0len = xres-floor(b0mapdelay/4); %number of points
    zerofill = zeros(xres-b0len,1)';
    [a b]= mexspiral([b0len,1,1000*fov rbw/1000 safety*smax/10 safety*gmax*100 k_a k_b density nucleus rhimsize]);
    b0traj = rampdown(safety*gmax*(a+1i*b));
    traj2(:,yres+1) = [b0traj' zerofill]';
    traj2(:,yres+2) = [zerofill b0traj']';
    yres = yres+2; %adding two here so the sequence plays the two field maps as well
end

%for now
%traj2 = pre_tag(80, traj2);
klocs = cumsum(traj2); %kspace location
if(nargout==0)
    clear G
    G(:,:,1) = real(traj2);
    G(:,:,2) = imag(traj2);
    %G = permute(G,[2 1 3]);
    inS=struct('FOV',fov,'mtx_res',length(traj2),'rBW',rbw,'Gmax',gmax,'Smax',smax,'G',G,'b0mapdelay',b0mapdelay,'npartitions',npartitions); %121023 added safety
    if nucleus==1
        nuc='H';
    elseif nucleus ==3
        nuc='He';
    else
        nuc='Xe';
    end
    % %invoke write waveform function
    outs = [nuc '-' num2str(xres) '-' num2str(yres) '-' num2str(fov) '-' num2str(1000*gmax) '-' num2str(b0mapdelay) '-' num2str(safety) '-v121023.wave'];
    wrt_wavs3d(inS,outs)
end

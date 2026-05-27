% function out=wrt_wavs3d(in,fname)
%
% Saves waveforms to external file using Stanford (John Pauly 
% and Adam B. Kerr) format. 
%
% INPUT (SI Units):
% in            ... Input structure
% in.G          ... [T/m] real gradient waveforms with time resolution 
%                   gdt=4us; size(in.G)=[#interleaves,#pts/interleave,#groups]
%                   with: #groups = 2 for 2d-imaging, =3 for 3d-imaging 
% in.Gmax       ... [T/m] Gradient amplitude hardware limit; scalar
% in.Smax       ... [T/m/s] Slewrate hardware limit; scalar
% in.rBW        ... [Hz] Readout (i.e. sampling) bandwidth; scalar
%         ... [m] Field-of-view; scalar
% in.mtx_res    ... [1] Image matrix resolution; scalar
%GL120514
%in.b0mapdelay .. delay in ms
% fname         ... [string] file name of output file
%
% OUTPUT (GE Scanner Units):
% out               ... Output structure
% out.des_wr        ... Descriptor string
% out.N.gdt         ... # input gradient pts/interleave
% out.N.kdt         ... # output data pts/interleave
% out.N.groups      ... # groups (=2; real and imaginary)
% out.N.intl        ... # interleaves
% out.N.params      ... # parameters (=19)
% out.parms=params  ... Header file parameters
% out.wave=wave     ... Output waveform
%
% TEST EXAMPLE: cf. test_wrt_wavs3d.m
%
% (C)   2007        Adam@mrsrl.stanford.edu 
% (M)   09/2007     Florian.Wiesinger@research.ge.com and Silke.Lechner@research.ge.com
% (M)   08/2008     Florian.Wiesinger@research.ge.com, Add gradient amplitude and slewrate check!
% (M)   10/2008     Florian.Wiesinger@research.ge.com, Add additional z-gradient

function out=wrt_wavs3d(in,fname)

% FIXED PARAMETERS
gdt=4;                  % [us] Gradient Sampling time; scalar
N.params=19;            % # parameters (=19)
%grad_type=0; 
grad_type = in.npartitions;%overloading this with the number of partitions
maps_exist=0; 
b0mapdelay=in.b0mapdelay; %120514

% DERIVED PARAMETERS: Plus conversion to GE scanner units/
G=in.G*1e2;                                   % [G/cm] Gradient waveforms; size(G) = #interleaves x #pts
Max.S_hw=in.Smax*1e-1;                        % [G/c/ms] Slew rate hardware limit; scalar
Max.G_hw=in.Gmax*1e2;                         % [G/cm] Gradient hardware limit; scalar
FOV=1e2*in.FOV;                               % [cm] Field of view; scalar
kdt=1/(2*in.rBW)*1e6;                         % [us] Sampling time; scalar 
[N.gdt,N.intl,N.groups]=size(G);              % [1] # pts per interleave, # of interleaves, # of groups
N.kdt=N.gdt*gdt/kdt;                          % [1] # readout pts

Max.G_read=max(max(max(abs(G))))                   % [G/cm] Max readout gradient; scalar
Max.S_read=max(max(max(abs(diff(G)/(1e-3*gdt)))))  % [G/cm/ms] Max readout slewrate; scalar
% Gradient Amplitude Checking
if Max.G_read > Max.G_hw
    disp('>> FW Warning:');
    disp(['Gradient amplitude violation: Max.G_read(=',num2str(round(Max.G_read*100)/100),...
          ') > Max.G_hw(=',num2str(round(Max.G_hw*100)/100),')']);
	disp(['Enforce rescaling according to: Max.G_read = Max.G_hw']),
    % Rescaling of gradient waveform
    G=G * Max.G_hw/Max.G_read; 
    Max.G_read=max(max(max(abs(G))));                  
    Max.S_read=max(max(max(abs(diff(G)/(1e-3*gdt))))); 
end
% Gradient Slew Rate Checking
if Max.S_read > Max.S_hw
    disp('>> FW Warning:');
    disp(['Gradient slewrate violation: Max.S_read(=',num2str(round(Max.S_read*100)/100),...
          ') > Max.S_hw(=',num2str(round(Max.S_hw*100)/100),')']);
	disp(['Enforce rescaling according to: Max.G_read = Max.G_read * Max.S_hw/Max.S_read']),
    % Rescaling of gradient waveform
    G=G * Max.S_hw/Max.S_read;
    Max.G_read=max(max(max(abs(G))));                  
    Max.S_read=max(max(max(abs(diff(G)/(1e-3*gdt))))); 
end
% Final Amplitude and Slew Rate Settings
disp('Final gradient amplitude and slewrate settings')
disp(['Max.G_read = ',num2str(round(Max.G_read*100)/100),' (<=',num2str(Max.G_hw),')']),
disp(['Max.S_read = ',num2str(round(Max.S_read*100)/100),' (<=',num2str(Max.S_hw),')']),

%=================================
% start: CREATE HEADER INFORMATION
%=================================
disp('Create header ...')
des=[sprintf('---------------------\n')];
des=[des sprintf('FILE DESCRIPTION:\n')];
des=[des sprintf('---------------------\n')];
des=[des sprintf('Smax: %4.2f G/cm/ms\n', Max.S_hw)];
des=[des sprintf('Gmax: %4.2f G/cm\n', Max.G_hw)];
des=[des sprintf('mxGrd: %4.2f G/cm\n', Max.G_read)];
des=[des sprintf('ilvs: %d\n', N.intl)];
des=[des sprintf('fov: %4.1f cm\n', FOV)];
des=[des sprintf('res: %5.2f mm\n', in.FOV/in.mtx_res*1e3)];
des=[des sprintf('npix: %dx%d\n', in.mtx_res, in.mtx_res)];
des=[des sprintf('grad: %d samp @ %dus (%6.3f ms)\n', N.gdt,gdt,N.gdt*gdt*1e-3)];
des=[des sprintf('k-sp: %d samp @ %dus (%6.3f ms)\n', N.kdt,kdt,N.kdt*kdt*1e-3)];
des=[des sprintf('%s \n', date)];
%des=[des sprintf('\n\n%s \n', date)];
% make length(des) = 256
des
%tmp=size(des,2); des=[des,reshape(meshgrid(' ',1:256-tmp),1,256-tmp)];
% Fix up descriptor
des_wr=char(zeros(1,256));
des_len=min(252,length(des));
des_wr(1:des_len)=des(1:des_len);
des_wr(des_len+1:des_len+3)=sprintf('\n\f\n');

% ADDITIONAL PARAMETERS
hw_array=hw_limits(G,gdt); % check HW limits

params=[grad_type FOV N.intl str2num(sprintf('%4.1f',Max.G_read)) N.gdt gdt ...
       N.kdt kdt 0 b0mapdelay 0 hw_array];
%===============================
% end: CREATE HEADER INFORMATION
%===============================

%================================
% start: WRITE HEADER + WAVEFORMS
%================================
% Int16 rounding + check that waveform is even
%121205
wave=2*round((2^14-1)/Max.G_read*...
       reshape(G,size(G,1),size(G,2)*size(G,3)));
   %I'm guessing there is an elegant way to do this
   %count=1;
%   for p = 1:N.intl
%       wave(:,N.groups*(p-1)+1:N.groups*p)= squeeze(G(:,p,:));
%       %count = count+N.groups;
%   end
%   
%   wave = 2*round((2^14-1)/Max.G_read*wave);
   
       
       

%gl skip this
%if sum(sum(abs(wave([1,end],:))))>eps     % changed from end-1 to end
%    error('>> FW Error: Gradient waveforms must start and end at 0!!');
%end
%glend

% Stop criterion: Last pt. of waveform must be odd (e.g.=1)
wave(end,:)=1;
% File IO: Open + Write + Close
fid=fopen(fname,'w','b');
if (fid==-1)
  error(['Could not write file: ',fname]);
end;
fwrite(fid, des_wr, 'char'); 
fwrite(fid, N.gdt, 'uint16');
fwrite(fid, N.groups, 'uint16');
fwrite(fid, N.intl*ones(1,N.groups), 'uint16');
fwrite(fid, N.params, 'uint16');
fwrite(fid, params, 'float64');
fwrite(fid, wave, 'int16');
fclose(fid);

% Create come output/feedback for control purposes
out.des_wr=des_wr;
out.N.gdt=N.gdt; out.N.kdt=N.kdt; out.N.groups=N.groups; 
out.N.intl=N.intl; out.N.params=N.params;
out.parms=params; out.wave=wave;
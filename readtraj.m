function [traj, dens, imsize, fov, bw] = readtraj
%assume the file is called
fname='kspc';
fid2 = fopen([fname '.hdr'],'r','l');
b = fread(fid2,'int32');
fclose(fid2);
x = b(1);
y= b(2);
imsize=b(3);
fov = b(4);
bw= b(5);
fid = fopen(fname,'r','l');
a = fread(fid,'float');
fclose(fid);
traj = a(1:3:length(a))+1i*a(2:3:length(a));
traj = reshape(traj,x,y);
dens = a(3:3:length(a));

%output = [ a(1:3:length(a)) a(2:3:length(a)) a(3:3:length(a))];

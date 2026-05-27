function outtraj = rampdown(traj)
%assume that traj is real and imaginary components
%take in only ONE trajectroy
% rotate it so that it ends on the positive x axis
% then ramp it down with a big circle

[q] = length(traj);
x = imag(traj(q));
y = real(traj(q));
if(y<0)
    extra=180;
else
    extra=0;
end
rt = rottraj(traj,-atand(x./y )+extra);
rewind = max(abs(rt)).*(exp(-1i*(0:pi/276:pi))/2+0.5);%120916 ramp down up from 200 to 276 points
outtraj = [rt;rewind(2:length(rewind))'];
%gauss = mat2gray(fspecial('gaussian',[1,512],sigma));
%rdown = mat2gray(gauss(290:490));
%rdown = rdown./rdown(1);
%start = 260;
%raround = mat2gray(gauss(start:start+200));
%raround = raround./(raround(1));
%for p = 1:y
%     for q=1:2
%         if(q==1)
%             tr = real(traj(:,p));
%         else
%             tr = imag(traj(:,p));  
%         end
%         dir=tr(x)-tr(x-1);
%         last = tr(x);
%         if( (dir>0 && last<0) || (dir<0 && last>0) )
%         %pointed in the right direction, just ramp down at the max
%         %which is 120g/cm/s * 0.0000004 seconds 
%         else
%             tr(x:x+200) = raround.*last;
%         end
%         if(q==1)
%             realtr = tr;
%         end
%     end
%     outtraj(:,p) = realtr+i*tr;
%end

    
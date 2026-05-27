function D = getdeap(G,Ggrid,w,beta)


% Beatty paper: c(x) = sin (sqrt(arg)) / sqrt(arg), where arg = (pi*w*x/G)^2 - beta^2

% HM 06/01/09 changed this from previous version to make 320x320
% deapodisation function

for i = 1:Ggrid                    % HM
    distx = abs(i-Ggrid/2);        % HM
    for j = 1:Ggrid                % HM
        disty = abs(j-Ggrid/2);    % HM    
      r = sqrt(distx*distx + disty*disty);

	if r > G/2			% circular deap function
	    r = G/2; 
	end
	 	arg = (pi*w*r/Ggrid)^2 - beta^2;
        	D(i,j) = sin(sqrt(arg))/sqrt(arg);
%             D(i,j) = D(i,j)./42.95;     % HM - factor changes depending on Ktab and C 
%               D(i,j) = D(i,j)./1180.88;   % w=6, beta = 10.9551
%               D(i,j) = D(i,j)./18991.72;  % w = 6, beta = 13.8551
    end
end

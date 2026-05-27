
function [hw_specs] = hw_limits (g, gsamp);
%
% hw_specs = hw_limits (g, gsamp);
%
% Inputs -
%		g - complex array of gradients, each column being a 
%		    waveform (Gx + i Gy)
%		gsamp - sample time for gradients in us
%
% Outputs - 	
%		hw_specs - a 1-D row vector with entries
%
% 		[grad_pow_x grad_pow_y grad_pos_pow grad_neg_pow grad_abs grad_dgdt grad_pwm]
%		
%		These entries are chosen to reflect worst-case obliquing of the
%		the input gradients.
%
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Author: Adam B. Kerr
%
% (c)2007 Board of Trustees
% Leland Stanford Junior University
%
% NOT TO BE USED OUTSIDE MRSRL WITHOUT WRITTEN PERMISSION OF AUTHOR
%
% $Header$
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


[n, nc] = size(g);  % original = don't delete
% HM 18/02/10, don't see why columns have to be longer than rows, commented out error
% if (n < nc),
% 	error ('hw_limits(): expects columns to be longer than rows...');
% end;

max_pow_x = 0;
max_pow_y = 0;
max_pos_pow = 0;
max_neg_pow = 0;
max_abs = 0;
max_dgdt = 0;
max_pwm = 0;
max_pwm_abs = 0;

dt = gsamp;

for j=1:nc, 
 	% get power in x and y 
	%
	gr = real(g(:,j));
	gi = imag(g(:,j));
	pow_x = sum(gr.^2) * dt;
	pow_y = sum(gi.^2) * dt;

	% get maximum of positive/negative powers between x and y...
	% This is making an assumption that obliquing won't change
	% the max positive power  
	%
	gr_p = gr;
	idx = find(gr_p < 0);
	gr_p (idx) = zeros(size(idx));
	gr_n = gr_p - gr;

	gi_p = gi;
	idx = find(gi_p < 0);
	gi_p (idx) = zeros(size(idx));
	gi_n = gi_p - gi;
	
	pos_pow = max([sum(gr_p.^2) sum(gi_p.^2)]) * dt;
	neg_pow = max([sum(gr_n.^2) sum(gi_n.^2)]) * dt;

	% get absolute average gradient 
	%
	avgabs = max([sum(abs(gr)) sum(abs(gi))]) * dt;

	% get average dgdt
	%
	dg_r = diff([0; gr])/(dt * 1e-6);
	dg_i = diff([0; gi])/(dt * 1e-6);
	dgdt = max([sum(abs(dg_r)) sum(abs(dg_i))]) * dt;

	% get pwm by looking for transitions on either axis 
	%
	dg = abs(diff([0; fix(g(:,j)*16383)]));
	nonzero_trans = find (dg > 0);
	pwm = length(nonzero_trans) * dt;

	% get abs pwm
	pwm_abs = max([sum(abs(gr(nonzero_trans))) sum(abs(gi(nonzero_trans)))]) * dt;

	% update maxima
	%
	max_pow_x = max([max_pow_x pow_x]);
	max_pow_y = max([max_pow_y pow_y]);
	max_pos_pow = max([max_pos_pow pos_pow]);
	max_neg_pow = max([max_neg_pow neg_pow]);
	max_abs = max([max_abs avgabs]);
	max_dgdt = max([max_dgdt dgdt]);
	max_pwm = max([max_pwm pwm]);
	max_pwm_abs = max([max_pwm_abs pwm_abs]);
end;

% return parameters now 
%
hw_specs = [max_pow_x max_pow_y max_pos_pow max_neg_pow max_abs max_dgdt max_pwm max_pwm_abs];

return;



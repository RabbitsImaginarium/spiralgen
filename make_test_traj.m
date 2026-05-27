function [ kl zl ] = make_test_traj( sz,slices )
k=mat2gray(ones(sz,1)*(1:sz));
k2 = k+i*k';
%k2 = k2./sz;
k3 = k2-0.5 -0.5*i;

for p = 1:slices
    k4(:,:,p) = k3;
    z(:,:,p) = p*ones(sz,sz);
end
zl = (mat2gray(z(:)))-0.5;
kl = k4(:);
    
end


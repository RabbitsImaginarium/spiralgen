TR = 24.5;
phases = 256;
slices = 80;
osf = zeros(phases,slices,8);
for g = 1:8
    partition =2^g;
    %generate a new sort
    eval(sprintf(['!./SATsort ' num2str(partition) ' ' num2str(phases) ' ' num2str(slices) ])); 
    a = csvread('postsort.csv');
    y = a(:,1);
    z = a(:,2);
    d = a(:,5);
    m =a(:,6);
    p =a(:,7);

    %to eliminate the zero vector
    y = y+1;
    z = z+1;
    for q= 1:length(z)
        osf(y(q),z(q),g) = m(q);
    end
    %imshow(log(abs(fftshift(ifft2(osf)))),[])
    figure(g)
    psf = (20*log(fftshift(abs(ifft2(osf(:,:,g))))));
    axis([0 80 0 256 -300 0])
    surf(psf);
    title(['PSF for ' num2str(g) ' Partitions']);
end

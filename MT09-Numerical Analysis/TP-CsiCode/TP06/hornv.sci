function [p] = hornv(a, t, theta)
    N = length(theta)
    p = zeros(1, N)
    tmp = 0 //pprim
    for i = 1:N
        [p(i), tmp] = horn(a, t, theta(i))
    end
endfunction

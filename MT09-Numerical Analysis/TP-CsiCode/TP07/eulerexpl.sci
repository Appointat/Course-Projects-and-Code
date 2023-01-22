function [z] = eulerexpl(a, t0, T, N, f)
    h = T/N
    m = length(a)
    z = zeros(m, N)
    z(:,1) = a
    for i=1:N-1
        z(:,i+1) = z(:,i) + h*f(t0 + (i-1) * h, z(:,i))
    end
endfunction

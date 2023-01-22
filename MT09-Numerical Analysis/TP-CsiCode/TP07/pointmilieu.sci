function [z] = pointmilieu(a, t0, T, N, f)
    h = T/N
    m = length(a)
    z = zeros(m, N)
    z(:,1) = a
    for i=1:N-1
        y = f(t0+(i-1)*h+h/2, z(i)+h/2*f(t0+(i-1)*h, z(i)))
        z(:,i+1) = z(:,i) + h*y
    end
endfunction

function [A] = construct(t, tau)
    index = place(t, tau)
    m = length(tau)
    n = length(t)
    A = zeros(m,n)
    for i=1:m
        j = index(i)
        A(i, j+1) = (tau(i)-t(j))/(t(j+1)-t(j))
        A(i, j) = (tau(i)-t(j+1))/(t(j)-t(j+1))
    end
endfunction

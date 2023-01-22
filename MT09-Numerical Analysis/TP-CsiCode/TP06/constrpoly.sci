function [A] = constrpoly(tau)
    m = length(tau)
    A = ones(m, 3)
    for i=1:m
        A(i,2) = tau(i)
        A(i,3) = tau(i)^2
    end
endfunction

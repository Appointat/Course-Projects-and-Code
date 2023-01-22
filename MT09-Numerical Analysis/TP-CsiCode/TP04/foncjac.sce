function [F, J]=foncjac(x)
    n = length(x);
    F = zeros(n,1);
    J = zeros(n,n);
    F(1) = x(1)^2 + x(2)^2 -4;
    F(2) = x(2) - exp(x(1));
    J(1,1) = 2*x(1);
    J(1,2) = 2*x(2);
    J(2,1) = -exp(x(1));
    J(2,2) = 1;
endfunction

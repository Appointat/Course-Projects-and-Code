function [F, J] = foncjac_ex4(v)
    deff('[b_vec] = b(x)', 'b_vec= -x.*(x-1)')
    deff('[g_vec] = g(x)', 'g_vec = 10*x./(1+x)')
    deff('[g_dif_vec] = g_dif(x)', 'g_dif_vec = 10./(1+x).*2')
    
    n = length(v) + 1;
    h = 1/n;
    x = (1:n-1)'/n;
    alp = 5;
    be  = 5;

    
    F = zeros(n-1,1);
    J = zeros(n-1,n-1);
    F(1) = -alp + 2*v(1) + h^2*g(v(1)) - v(2) - h^2*b(x(1));
    F(n-1) = -v(n-2) + 2*v(n-1) + h^2*g(v(n-1)) - be - h^2*b(x(n-1));
    J(1,1) = 2 + h^2*g_dif(v(1));
    J(1,2) = -1;
    J(n-1,n-2) = -1;
    J(n-1,n-1) = 2 + h^2*g(v(n-1));
    for i=2:n-2
        F(i) = -v(i-1) + 2*v(i) + h^2*g(v(i)) - v(i+1) - h^2*b(x(i));
        J(i, i-1) = -1;
        J(i, i) = 2 + h^2*g_dif(v(i));
        J(i, i+1) = -1;
    end
endfunction

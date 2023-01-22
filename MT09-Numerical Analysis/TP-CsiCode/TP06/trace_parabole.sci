function [] = trace_parabole(tau, y)
    A = constrpoly(tau);
    x = mcnorm(A, y);
    
    left = tau(1)-(tau($)-tau(1))*0.1;
    right = tau($)+(tau($)-tau(1))*0.1;
    N = 100;
    t = (linspace(left, right, N))'
    A_t = constrpoly(t)
    plot(t, A_t*x)
    plot(tau, y, "o")
endfunction

function [] = trace_ex2(t, tau, y)
    A = construct(t, tau);
    z = mcnorm_ex2(A, y);
    
    left = tau(1)-(tau($)-tau(1))*0.1;
    right = tau($)+(tau($)-tau(1))*0.1;
    N = 100;
    x = (linspace(left, right, N))'

    A_x = construct(t, x)
    //disp(size(A_x), size(z), size(x))
    plot(x, A_x*z)
    plot(tau, y, "o")
endfunction

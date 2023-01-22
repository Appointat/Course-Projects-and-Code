function [] = courbe(N)
    x = linspace(-2, 2, N)';
//    F1 = (x*ones(1,N)).*2 + (ones(N,1)*x').^2 - 4;
//    F2 = ones(N,1)*x' - exp(x*ones(1,N));
//    plot3d(x, x, F1);
//    plot3d(x, x, F2);
    F1 = sqrt(4-x.^2);
    F2 = exp(x);
    plot(x, F1);
    plot(x, -F1);
    plot(x, F2);
endfunction

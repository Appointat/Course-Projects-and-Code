function [] = trace_ex4(v)
    alp = 5;
    beta = 5;
    n = length(v) + 1;
    x = (1:n-1)'/n;
    x = [0; x];
    v = [alp; v];
    
    plot(x, v);
endfunction

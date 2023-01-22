function [x0]=resolG(A, b)
    [U, e] = trisup(A, b);
    x0 = solsup(U, e);
endfunction

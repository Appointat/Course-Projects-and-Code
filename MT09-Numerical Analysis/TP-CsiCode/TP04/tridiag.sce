function [x, k]=tridiag(n)
    A = 3*eye(n,n);
    A(1,2) = 1;
    A(n,n-1) = 1;
    for i = 2:n-1
        A(i,i-1) = 1;
        A(i,i+1) = 1;
    end

    b = ones(n,1);
    
    x0 = ones(n,1);
    tol = 1e-8;
    N = 100;
    [x, k] = gausseidel(A, b, tol, N, x0);
endfunction

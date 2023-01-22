function [x] = mcnorm_ex2(A, y)
    //x = (A'*A)\(A'*y)
    M = A'*A
    m = size(M,1)
    a = zeros(m-1)
    b = zeros(m)
    c = zeros(m-1)
    b(1) = M(1,1)
    c(1) = M(1,2)
    for i=2:m-1
        a(i-1) = M(i,i-1)
        b(i) = M(i,i)
        c(i) = M(i,i+1)
    end
    a(m-1) = M(m,m-1)
    b(m) = M(m,m)
    u = A'*y;
    
    x = rich(a, b, c, u)
endfunction

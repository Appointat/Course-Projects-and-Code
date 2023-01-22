function [B] = inverse(A)
    n = size(A,2);
    B = eye(n,n);
    I = eye(n,n)
    for i=1:n
        B(:,i) = resolG(A, I(:,i));    
    end
endfunction

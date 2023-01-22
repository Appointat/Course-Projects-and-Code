function [L, U]=LU(A)
    n = size(A,2);
    tol = 1e-6;
    U = A;
    L = eye(n, n);
    for j = 1:n
        if abs(U(j,j)) > tol
            for i = j+1:n
                coe = U(i,j) / U(j,j);
                L(i,j) = coe;
                U(i,:) = U(i,:) - coe * U(j,:);
            end
        else
            error("pivot nul");
        end
    end
endfunction

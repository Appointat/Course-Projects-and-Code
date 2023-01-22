function [A, b]=trisup(A, b)
    n = size(A,2);
    tol = 1e-6;
    for j = 1:n
        if abs(A(j,j)) > tol
            for i = j+1:n
                coe = A(i,j) / A(j,j);
                b(i) = b(i) - coe * b(j);
                A(i,:) = A(i,:) - coe * A(j,:);
            end
        else
            error("pivot nul");
        end
    end
endfunction

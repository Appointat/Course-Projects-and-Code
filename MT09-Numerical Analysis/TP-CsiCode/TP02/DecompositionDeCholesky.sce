function [C]=DecompositionDeCholesky(A)
    tol = 1e-6;
    n = size(A,2);
    C = zeros(n,n);
    
    sum = 0;
    C(1) = sqrt(A(1));
    C(:,1) = A(:,1)/C(1);
    
    for i = 2:n
        // pour A(i,j), i \ne j
        for j = 2:i-1 //
            C(i,j) = (A(i,j) - C(i,1:j-1)*(C(j,1:j-1))')/C(j,j);
        end

        Cii = A(i,i) - C(i,1:i-1)*(C(i,1:i-1))';
        if Cii < tol // Cjj > tol > 0
            error("La matrice non SDP");
        else
            C(i,i) = sqrt(Cii);
        end
    end
endfunction

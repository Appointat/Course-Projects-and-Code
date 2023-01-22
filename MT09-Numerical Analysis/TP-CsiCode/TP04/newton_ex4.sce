function [x, k]=newton_ex4(foncjac, tol, N, x0)
    x = x0;
    y = x0;
    for k=1:N
        [F, J] = foncjac_ex4(x);
        // J(x)(x-x) = F
        if abs(det(J))<tol then
            error('Matrice de Jacobi nest pas inversible, changez un vetcteur initial.')
        end

        y = x - inv(J)*F; // 2*1,2,2
        
        if norm(y-x)/norm(y)<tol then
            break;
        elseif k==N then
            error('Nowton methode nest pas convergente');
        end
        
        x = y;
    end
endfunction

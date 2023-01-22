function [x, k]=newton(foncjac, tol, N, x0)
    x = x0;
    y = x0;
    for k=1:N
        [F, J] = foncjac(x);
        if abs(det(J))<tol then
            error('Matrice de Jacobi nest pas inversible, changez un vetcteur initial.')
        end

        y = x - inv(J)*F; // 2*1,2,2
        
        // y = x - gausseidel(J, F, tol, N, x0+1);
        
        // disp(norm(y-x))
        
        if norm(y-x)/norm(y)<tol then
            break;
        elseif k==N then

            error('Nowton methode nest pas convergente');
        end
        
        x = y;
    end
    //courbe(100);
endfunction

function [x, k] = gausseidel(A, b, tol, N, x0)
// A, b,        
// tol = tolérance à 1e-6
// N = nombre maxime de l'itération
// x0 = vecteur initial de solution x
// Ax = b
if (size(A, 1)~=size(A, 2)) then
    error('Matrice A nest pas carrée');
end

n = size(A,1);
D = zeros(n, n);
E = zeros(n, n);
F = zeros(n, n);

// if (norm(x0)==0) then
    // error('x0 un vecteur nul');
// end
for i=1:n
    if (abs(A(i,i))<tol) then
        error('diagonale de A nulle');
    end
    D(i,i) = A(i,i);
end

for i=1:n
    for j=1:i-1
        E(i,j) = -A(i,j);
    end
end

for i=1:n
    for j=i+1:n
        F(i,j) = -A(i,j);
    end
end
// disp (E, F, D);
// (D - E)x = Fx + b    

x = x0; // Firstly, I am debugging now, you can do something else if you want...

y = x0;
for k=1:N
    for i=1:n
        s = 0
        if (i==1) then
            s = A(i,i+1:n)*x(i+1:n);
        elseif (i==n)
            s = A(i,1:i-1)*y(1:i-1);
        else
            s = A(i,1:i-1)*y(1:i-1) + A(i,i+1:n)*x(i+1:n);
        end
        y(i) = (b(i)-s)/A(i,i);
    end


    if (norm(y-x)/norm(y)<=tol && norm(A*y-b)<=tol)
        break;
    else
        x = y;
        if (k == N) then
            error('Methode de GS nest pas convergente');
        end
    end

    //disp(x, k)
end

endfunction

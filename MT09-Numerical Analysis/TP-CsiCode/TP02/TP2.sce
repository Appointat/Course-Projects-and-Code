clc;

A = [1 2 3;
     0 4 8;
     0 0 5];
b = [6 16 15]';
x0 = solsup(A, b)
disp(x0)
disp(inv(A)*b)

A = [3, 1, 2; 
    3, 2, 6; 
    6, 1, -1];
b = [2; 1; 4];
[U, e] = trisup(A, b)
disp(U, e)

A = [1, 2, 3;
     5, 2, 1;
     3,-1, 1];
b = [5; 5; 6];
x0 = resolG(A, b);
disp(x0)
disp(A^-1*b)

A  = [1, 2, 3;
     5, 2, 1;
     3,-1, 1];
 [L, U] = LU(A);
 disp(L,U)
disp(L*U)

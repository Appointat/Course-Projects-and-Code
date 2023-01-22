// main
A = [1 1 1; 1 3 1; 1 2 2]; // note : la convergence
b = [7; 13; 13];

A = [1 2 2; 3 1 4; 5 3 1]; // pas convergent
b = [3; 7; 6];

A = [8 -3 2; 4 11 -1; 6 3 12]; // convergent
b = [20; 33; 36];

A = [1 -2 2; -1 1 -1; -2 -2 1];
b = [7; -4; 2]; // pas convergent

A = [1 -1 -2; -2 1 3; 0 2 1]; // OK
b = [-2; 3; 0];
// x = [1; -1; 2];

tol = 1e-6;
N = 100;
[x, k] = gausseidel(A, b, tol, N, (1:3)') // x0

[x, k]=newton(foncjac, tol, N, [1;2])

[v, k]=newton_ex4(foncjac, tol, N, (1:20)'); trace_ex4(v);


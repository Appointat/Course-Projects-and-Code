clc;
C = [2, 0, 0;
     1, 4, 0;
     3, 2, 2;];

A = C*C';
C_cal = DecompositionDeCholesky(A);
disp (C_cal);

function [x0] = resolLU(A, b)
    [L, U] = LU(A);
    // LUx = b, Ly = b, Ux = y
    y0 = solinf(L, b);
    x0 = solsup(U, y0);
endfunction

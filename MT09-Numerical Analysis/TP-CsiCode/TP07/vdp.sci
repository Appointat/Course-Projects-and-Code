function [Y] = vdp(t, X)
    c = 0.4
    A = [0, 1; -1, c*(1-X(1)^2)]
    Y = A * X
endfunction

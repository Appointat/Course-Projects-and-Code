function [p] = interpol(y, t, theta)
    a = diffdiv(y, t)
    p = hornv(a, t, theta)
    // plot(theta, p)
endfunction

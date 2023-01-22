function coubre(y, t, N, tau)
    n = length(y)
    left = t(1)
    right = t(n)
    x = linspace(left, right, N)
    p = interpol(y,t,x)
    
    a = diffdiv(y, t)
    [tmp, pprim] = horn(a, t, tau)
    lin_y = pprim * (x-tau) + tmp;
    
    plot(x, p)
    scatter(t, y, "diamond plus")
    if tau > -10 then
        plot(x, lin_y)
    end
endfunction

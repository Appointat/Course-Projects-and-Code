function coubre(y, t)
    n = length(y)
    left = t(1) - (t(n)-t(1))*0.1
    right = t(n) + (t(n)-t(1))*0.1
    N = 100
    x = linspace(left, right, N)
    p = interpol(y,t,x)
    
    //a = diffdiv(y, t)
    //[tmp, pprim] = horn(a, t, tau)
    //lin_y = pprim * (x-tau) + tmp;
    
    plot(x, p)
    scatter(t, y, "diamond plus")
    //if tau > -10 then
        //plot(x, lin_y)
    //end
endfunction

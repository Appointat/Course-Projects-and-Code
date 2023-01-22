function [x] = rich(a, b, c, u)
    if size(a,1)>size(a,2) then
        a = [0; a];
    else
        a = [0 a];
    end
    if size(c,1)>size(c,2) then
        c = [c; 0];
    else
        c = [c 0];
    end
    n = length(b);
    e = zeros(n);
    f = zeros(n);
    i=1;
    e(i) = -c(i)/b(i);
    f(i) = u(i)/b(i);
    for i=2:n-1
        e(i) = - c(i)/(a(i)*e(i-1)+b(i));
        f(i) = (u(i)-a(i)*f(i-1))/(a(i)*e(i-1)+b(i));
    end
    i = n;
    f(i) = (u(i)-a(i)*f(i-1))/(a(i)*e(i-1)+b(i));
    
    x(n) = f(n)
    for i=n-1:-1:1
        x(i) = e(i)*x(i+1)+f(i);
    end
endfunction

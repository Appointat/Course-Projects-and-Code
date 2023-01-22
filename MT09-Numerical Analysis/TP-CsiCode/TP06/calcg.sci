function [z]=calcg(T, y)
    n = length(T)
    h = zeros(n-1)
    for i=1:n-1
        h(i) = T(i+1) - T(i)
    end
    
    a = zeros(n-1)
    b = zeros(n)
    c = zeros(n-1)
    yy = zeros(n)
    b(1) = 2/h(1)
    c(1) = 1/h(2)
    yy(1) = 3*(y(2)-y(1))/h(1)^2
    for i=2:n-1
        a(i-1) = 1/h(i-1)
        b(i) = 2*(1/h(i)+1/h(i-1))
        c(i) = 1/h(i)
        yy(i) = 3*((y(i)-y(i-1))/h(i-1)^2 + (y(i+1)-y(i))/h(i)^2)
    end
    a(n-1) = 1/h(n-1)
    b(n) = 2*(1/h(n-1))
    yy(n) = 3*(y(n)-y(n-1))/h(n-1)^2
    
    d = rich(a, b, c, yy)

    cc = zeros(n-1,3)
    for i=1:n-1
        cc(i,1) = y(i)
        cc(i,2) = d(i)
        cc(i,3) = (y(i+1)-y(i))/h(i)^2 - d(i)/h(i)
        cc(i,4) = (d(i+1)+d(i))/h(i)^2 - 2*(y(i+1)-y(i))/h(i)^3
    end
    
    N = 100
    left = T(1)
    right = T($)
    t = linspace(left, right, N)
    index = place(T, t);
    for i=1:N
        if t(i)==T(n) then
            z(i) = cc(n-1,1)+cc(n-1,2)*(t(i)-T(n-1))+cc(n-1,3)*(t(i)-T(n-1))^2
        else
            z(i) = cc(index(i),1)+cc(index(i),2)*(t(i)-T(index(i)))+cc(index(i),3)*(t(i)-T(index(i)))^2+cc(index(i),4)*(t(i)-T(index(i)))^2*(t(i)-T(index(i)+1))
        end
    end
    
    plot(t, z, 'r')
    plot(T, y, 'o')
endfunction

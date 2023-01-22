function [cc]=spline(y, t)
    n = length(y)-1
    h = zeros(1, n)
    for i=1:n
        h(i) =  t(i+1) - t(i)
    end
    Y = zeros(n+1,1)
    Y(1) = 0
    Y(n+1) = 0
    A = zeros(n+1,n+1)
    A(1,1) = 1
    A(n+1,n+1) = 1
    for i=2:n
        A(i,i-1) = h(i-1)
        A(i,i) = 2*(h(i-1)+h(i))
        A(i,i+1) = h(i)
        Y(i) = 6*(y(i+1)-y(i))/h(i) - 6*(y(i)-y(i-1))/h(i-1)
    end
    M = inv(A)*Y    
    a = zeros(n,1)
    b = zeros(n,1)
    c = zeros(n,1)
    d = zeros(n,1)
    for i = 1:n
        d(i) = (M(i+1)-M(i))/(6*h(i))
    end
    c = M(1:n)/2
    a = y(1:n)'
    for i=1:n
        b(i) = (y(i+1)-y(i))/h(i) - h(i)*M(i)/2 - h(i)/6*(M(i+1)-M(i))
    end
    cc = [a b c d]

endfunction

function [cc]=calcg(y, T)
    cc = spline(y,T)
    N = 100
    x = linspace(T(1), T($), N)
    index = place(T, x);
    z = zeros(N)
    for i=1:N
        z(i) = cc(index(i),1) + cc(index(i),2)*(x(i)-T(index(i))) + cc(index(i),3)*(x(i)-T(index(i)))^2 + cc(index(i),4)*(x(i)-T(index(i)))^3
    end
    plot(x,z)
    //if (t==T($)) then
    //    z = cc(index,1)+cc(index,2)*(t-T(index))+cc(index,3)*(t-T(index))^2;
    //else
    //    z = cc(index,1)+cc(index,2)*(t-T(index))+cc(index,3)*(t-T(index))^2+cc(index,4)*(t-T(index))^2*(t-T(index+1));
    //end
endfunction

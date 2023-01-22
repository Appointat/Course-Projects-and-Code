function [cc]=calcoef(T, y)
    n = length(T);
    cc = zeros(n-1, 4);
    
    h = zeros(n-1,0);
    for i=1:n-1
        h(i) = T(i+1)-T(i);
    end
    
    d = cald(T, y);
    for i=1:n-1
        cc(i,1) = y(i);
        cc(i,2) = d(i);
        cc(i,3) = (y(i+1)-y(i))/(h(i)^2)-d(i)/h(i);
        cc(i,4) = (d(i+1)+d(i))/(h(i)^2) - 2*(y(i+1)-y(i))/(h(i)^3);
    end
endfunction

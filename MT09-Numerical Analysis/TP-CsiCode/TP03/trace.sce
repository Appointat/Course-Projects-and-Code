function []=trace(N, T, cc)
    t = linspace(T(1), T($), N);
    index = place(T, t);

    g = zeros(1,N);
    for i=1:N
        g(i) = cc(index(i),1)+cc(index(i),2)*(t(i)-T(index(i)))+cc(index(i),3)*(t(i)-T(index(i)))^2+cc(index(i),4)*(t(i)-T(index(i)))^2*(t(i)-T(index(i)+1));
    end
    plot(t, g);
endfunction

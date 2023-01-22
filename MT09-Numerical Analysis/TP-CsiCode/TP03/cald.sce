function [d]=cald(T, y)
    n = length(T);
    h = zeros(n-1,0);
    for i=1:n-1
        h(i) = T(i+1)-T(i);
    end
    a = zeros(n);
    b = zeros(n);
    c = zeros(n);
    b(1) = 2/h(1);
    for i=1:n-2
        a(i+1) = 1/h(i);
        b(i+1) = 2/h(i)+2/h(i+1);
        c(i) = 1/h(i);
    end
    i =n-1;
    a(i+1) = 1/h(i);
    c(i) = 1/h(i);
    b(n) = 2/h(n-1);
    // a = [0 1 2 1 2]';
    // b = [2 3 1 1 1]';
    // c = [3 1 2 1 0]';
    d = rich(a(2:n), b, c(1:n-1), y);
    //disp (a(2:n))
    //disp (b)
    //disp (c(1:n-1))
endfunction

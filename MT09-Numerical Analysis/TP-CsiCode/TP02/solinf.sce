function[x] = solinf(U,b)
    [n,m] = size(U)
    x = zeros(n,1)
    x(1) = b(1) / U(1,1)
    for i = 2:n
            s = 0
        for j = 1:i-1
            s = s + U(i,j)*x(j)
            end
        x(i) = (1/U(i,i))*(b(i)-s)
    end
endfunction

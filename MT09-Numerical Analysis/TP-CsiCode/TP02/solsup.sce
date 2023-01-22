function[x] = solsup(U,b)
    [n,m] = size(U)
    x = zeros(n,1)
    x(n) = b(n) / U(n,n)
    for i = (n-1):-1:1
            s = 0
        for j = (i+1):n
            s = s + U(i,j)*x(j)
            end
        x(i) = (1/U(i,i))*(b(i)-s)
    end
endfunction

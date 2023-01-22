function [d]=diffdiv(y, t)
    d = y;
    n = length(y);
    if n==1 then
        error("The length of the vector should greater than 1.")
    end
    for k=2:n
        for i=n:-1:k
            d(i) = (d(i)-d(i-1))/(t(i)-t(i-k+1))
        end
    end
    
    // disp(d)
    polynome(t, d) // plot
endfunction

function polynome(t0, d)
    n = length(d)
    N = 100
    left = t0(1)
    right = t0(n)
    t = linspace(left, right, N)

    p = 0
    for i=1:n
        m = ones(1,N)*d(i);
        for k=1:i-1
            tmp = (t-t0(k))
            m = m .* tmp
        end
        p = p + m
    end

    plot(t, p)
endfunction

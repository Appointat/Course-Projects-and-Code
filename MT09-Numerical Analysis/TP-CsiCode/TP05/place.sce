function [i]=place(T, t)
    n = length(T);
    m = length(t);
    i = [];

    for k=1:m
        imin = 1;
        imax = n;
        while (imax>imin+1)
            mil = floor((imax+imin)/2);
            if (t(k) >= T(mil))
                imin = mil;
            else
                imax = mil;
            end
        end
        i = [i; imin];
    end
endfunction

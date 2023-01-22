function [p, pprim] = horn(a, t, theta)
    //funcprot(0)
    n = length(a)
    p = a(n)
    pprim = a(n)
    for i=n-1:-1:2//1:n
        p = p*(theta-t(i)) + a(i) // Algorithme de Horner
        pprim = pprim*(theta-t(i-1)) + p // pprim
    end
    p = p*(theta-t(1)) + a(1)
endfunction

    //tol = 1e-7
    //theta2 = theta + tol
    //p2 = a(n)
    //for i=n-1:-1:1
        // m = a(i);
        //for k=1:i-1
        //    tmp = (theta2-t(k))
        //    m = m * tmp
        //end // p=a(n)
    //    p2 = p2*(theta2-t(i)) + a(i)
    //end
    // disp([theta, p,p2, a])
    //pprim = (p2-p)/tol



//    for i=n-1:-1:1//1:n
        //m = a(i);
        //for k=1:i-1
        //    tmp = (theta-t(k))
        //    m = m * tmp
        //end
        //p = p + m
//        p = p*(theta-t(i)) + a(i)
//    end

// 1 + 3t + 5t^2 + -1*t^2(t-1)
// 2
// 1 + 6 + 20 - 4
// 3 + 10t -3t^2 + 2t
// 3 + 20 - 12 + 4

// theta = 4
// 1 + 12 + 80 - 48  = 13+32 = 45
// a*xyz + b *xy + c*x + d= x(c+y(az+b))) + d

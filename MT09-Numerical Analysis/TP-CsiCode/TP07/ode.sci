function [z] = eulerexpl_2(a, t0, T, N)
    h = T/N
    m = length(a)
    z = zeros(m, N)
    z(:,1) = a
    for i=1:N-1
        z(:,i+1) = z(:,i) + h*vdp(t0 + (i-1) * h, z(:,i))
    end
endfunction


function tracevdp_2(a, t0, T, Neul, Nptmil)
    z = zeros(2, Nptmil)
    z(:,1) = a
    Y = zeros(2,1)
    h = T/Nptmil
    for i=1:Nptmil-1
        Y = vdp(t0+(i-1)*h+h/2, z(:,i)+h/2*vdp(t0+(i-1)*h, z(:,i)))
        
        //disp(y)
        z(:,i+1) = z(:,i) + h.*Y
    end
    //plot(t0+(0:N-1)*T/N, z(2,:))
    plot(z(1,:), z(2,:))
    N = Neul
    zz = eulerexpl_2(a, t0, T, Neul)    
    plot(zz(1,:), zz(2,:), "r")
    
    // ODE funciton
    deff('[Y] = vdp2(t, X)', ['c=0.4;A = [0, 1; -1, c*(1-X(1)^2)]; Y=A*X'])// in-line
    theta = t0 + (0:N-1)*h
    zzz = ode(a, t0, theta, vdp)
    plot(zzz(1,:), zzz(2,:), "g")
endfunction

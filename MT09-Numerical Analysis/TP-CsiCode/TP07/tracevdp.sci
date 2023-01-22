function tracevdp(a, t0, T, Nptmil)
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
endfunction

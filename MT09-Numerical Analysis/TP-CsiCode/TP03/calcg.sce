function [z]=calcg(t, T, cc)
    index = place(T, t);
    if (t==T($)) then
        z = cc(index,1)+cc(index,2)*(t-T(index))+cc(index,3)*(t-T(index))^2;
    else
        z = cc(index,1)+cc(index,2)*(t-T(index))+cc(index,3)*(t-T(index))^2+cc(index,4)*(t-T(index))^2*(t-T(index+1));
    end
endfunction

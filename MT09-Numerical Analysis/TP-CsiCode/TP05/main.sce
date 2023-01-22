t = [0 1 2 3] // poly
y = [1/2 1 2 -1/2]
// f = diffdiv(y, t)


t = [1 3 4.5 5 6]
y = [1 5 3 7 -1]

// Ex1.
t = [-2 0 2]
y = [5 -1 5]
f = diffdiv(y, t)

t = [-1 0 2]
y = [5 -1 5]
// f = diffdiv(y, t)

// Ex2.a
a = [1 3 5 -1]
t = [0 0 1]
theta = 2
[p, pprim]=horn(a,t,theta)
// disp(p, pprim)

// Ex2.b
a = [1 3 5 -1]
t = [0 0 1]
theta = [2 4]
[p] = hornv(a,t,theta)


// Ex3.a
t = [1 3 4.5 5 6]
y = [1 5 3 7 -1]
theta = 3; // 4
[p] = interpol(y, t, theta)


// Ex3.b
t = [1 3 4.5 5 6]
y = [1 5 3 7 -1]
tau = 4
N = 100
coubre(y, t, N, tau)

// Ex4.a, Ex4.b
t = linspace(0,1,11)
y = [0 0 0 0 0 0 10 0 0 0 0]
tau = 3
coubre(y, t, N, tau)
cc = calcg(y,t)




function [z] = dif2(x, cc, i, x0)
    z = 2*cc(i,3) + 6*cc(i,3)*(x-x0)
endfunction

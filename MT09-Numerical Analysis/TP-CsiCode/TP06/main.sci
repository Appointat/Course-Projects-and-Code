tau = [0, 1, 2]'
A = constrpoly(tau)

y = [3, -3, 6]'
x = mcnorm(A, y)

// 2.(b) trace
//trace_parabole(tau, y)

// 2.(c)
// x = (A^T*A)^(-1)*(A^T*y)
tau = (0:0.25:2)'
y = [-1 -0.71 0.94 1.82 3.02 2.94 1.44 0.92 -0.62]'
//trace_parabole(tau, y)



// Ex.1.c
t = [0 1 3 4 5.5 6]'
tau = t
A = construct(t, tau)

// Ex.1.d
t = [0 1 3 4 5.5 6]'
tau = [0.5 2 2.5 3.5 4.5 5.75]'
A = construct(t, tau)

// Ex.1.e
t = [0 1 3 4 5.5 6]'
tau = (0.3*((1:21)-1))'
A = construct(t, tau)


// Ex,2.b
t = [0 1 3 4 5.5 6]'
tau = [0.5 2 2.5 3.5 4.5 5.75]'
y = [1 1.5 1.25 0 0 1.5]'
A = construct(t, tau)
x = mcnorm(A, y)
// parce que ||A*x-y|| = 0
// trace_ex2(t, tau, y)

// Ex.2.c
t = [0 1 3 4 5.5 6]'
tau = (0.3*((1:21)-1))'
y = [0 0.6 1.4 1.7 2.1 1.9 1.6 1.4 1.4 1 0.5 0.4 -0.2 -0.8 -0.5 0 0.4 1 1.6 1.7 1.2]'
A = construct(t, tau)
z = mcnorm_ex2(A, y)
trace_ex2(t, tau, y)

// Ex.4.1
t = [0 1 3 4 5.5 6]'
tau = [0.5 2 2.5 3.5 4.5 5.75]'
y = [1 1.5 1.25 0 0 1.5]'
A = construct(t, tau)
x = mcnorm(A, y)
trace_ex2(t, tau, y)
coubre(y, tau)
z = calcg(tau, y);

// Ex.4.2
t = [0 1 3 4 5.5 6]'
tau = (0.3*((1:21)-1))'
y = [0 0.6 1.4 1.7 2.1 1.9 1.6 1.4 1.4 1 0.5 0.4 -0.2 -0.8 -0.5 0 0.4 1 1.6 1.7 1.2]'
A = construct(t, tau)
x = mcnorm(A, y)
trace_ex2(t, tau, y)
coubre(y, tau)
z = calcg(tau, y);

// Pre 3/4/5
deff('[v] = funexpt2(theta, u)', ['v = u + theta^2']) // in-line function
deff('[y] = fun(x, a)', ['C = 2+a; y = C*exp(x)-x^2-2*x-2'])
// y = C*exp(x)-x^2-2*x-2

a = 0
t0 = 0
T = 5
// N = 10
N = 10
[z] = eulerexpl(a, t0, T, N, funexpt2)
plot(t0+(0:N-1)*T/N, z)
plot(t0+(0:N-1)*T/N, fun(t0+(0:N-1)*T/N, a), "r")

N = 20
[z] = eulerexpl(a, t0, T, N, funexpt2)
plot(t0+(0:N-1)*T/N, z)
plot(t0+(0:N-1)*T/N, fun(t0+(0:N-1)*T/N, a), "r")

N = 50
[z] = eulerexpl(a, t0, T, N, funexpt2)
plot(t0+(0:N-1)*T/N, z)
plot(t0+(0:N-1)*T/N, fun(t0+(0:N-1)*T/N, a), "r")


// ********
// TP07
// ********
// Ex2
a = [2;-2]
t0 = 0
T = 15
N = 100
tracevdp(a, t0, T, N)
//deff('[Y] = vdp(t, X)', ['c=0.4;Y = c*(1-X(2)^2)*X(1)-X(2)'])
Neul = 100
Nptmil = 100
tracevdp_2(a, t0, T, Neul, Nptmil)



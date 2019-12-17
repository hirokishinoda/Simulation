import sympy
import numpy as np
from sympy.plotting import plot

data = np.loadtxt('data.dat', delimiter=' ', dtype='int64')
data = data.tolist()

N = len(data)

x = sympy.Symbol('x')
y = 0

for k in range(N):
    zk = 1
    for i in range(N):
        if k is not i:
            zk *= ((x - data[i][0]) / (data[k][0] - data[i][0]))
    y += data[k][1]*zk

print(sympy.expand(y))

plot(y, (x, -2, 2))

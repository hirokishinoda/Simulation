import sympy
import numpy as np
from sympy.plotting import plot
import matplotlib.pyplot as plt

def f(x):
    return 1 / (1 + 25*x**2)

split_num = 21
data = []
for i in range(split_num+1):
    x = -1 + 2/split_num * i
    data.append([x,f(x)])
print(data)

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

plot(y)
plot(f(x))

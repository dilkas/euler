import operator

def u(n):
    return sum((-n) ** i for i in range(11))

s = 0
for k in range(1, 11):
    P = lambda x: sum(u(i + 1)
                      * reduce(operator.mul, [x - j - 1
                                              for j in range(k)
                                              if j != i], 1)
                      / reduce(operator.mul, [i - j
                                              for j in range(k)
                                              if j != i], 1)
                      for i in range(k))
    k2 = k + 1
    while u(k2) == P(k2): k2 += 1
    s += P(k2)
print s

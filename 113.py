import functools, operator

def binomial(n, k):
    return int(functools.reduce(operator.mul,
                                [(n - i) / (i + 1)
                                 for i in range(min(k, n - k))]))

print(binomial(110, 100) + binomial(109, 9) - 1001)

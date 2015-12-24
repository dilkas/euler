import math

def sieve(n):
    A = [True] * (n + 1)
    for i in range(2, math.floor(n ** 0.5) + 1):
        if not A[i]: continue
        for j in range(i * i, n + 1, i): A[j] = False
    return [i for i in range(2, n + 1) if A[i]]

p = sieve(2 ** 20) # guessing is faster
n = 7038 # our indices start at 0, not 1
while p[n] * n <= (10 ** 10) / 2:
    n += 2 # only odd n's (or even indices) can be that big
print(n + 1)

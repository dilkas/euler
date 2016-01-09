import math

LIMIT = 50 * 10 ** 6

def sieve_of_eratosthenes(n):
    A = [True] * (n + 1)
    for i in range(2, math.floor(n ** 0.5) + 1):
        if not A[i]: continue
        for j in range(i * i, n + 1, i): A[j] = False
    return [i for i in range(3, n + 1) if A[i]]

primes = sieve_of_eratosthenes(LIMIT - 1)
count = 0
for p in [1] + primes:
    if p < LIMIT / 4: count += 1
    if p < LIMIT / 16: count += 1
    if p % 4 == 3: count += 1
print(count)

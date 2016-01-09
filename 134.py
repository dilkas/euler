import math

MIN_PRIME = 5
MAX_PRIME = 10 ** 6 + 3

def sieve_of_eratosthenes(n):
    A = [True] * (n + 1)
    for i in range(2, math.floor(n ** 0.5) + 1):
        if not A[i]: continue
        for j in range(i * i, n + 1, i): A[j] = False
    return [i for i in range(MIN_PRIME, n + 1) if A[i]]

def inverse(a, n):
    "Calculates the inverse of a modulo n."
    t, newt = 0, 1
    r, newr = n, a
    while newr != 0:
        quotient = r // newr
        t, newt = newt, t - quotient * newt
        r, newr = newr, r - quotient * newr
    if r > 1: print("bug?")
    if t < 0: t += n
    return t

def S(p1, p2):
    first_half = 10 ** len(str(p1))
    return (((p2 - p1) * inverse(first_half, p2)) % p2) * first_half + p1

primes = sieve_of_eratosthenes(MAX_PRIME)
print(sum(S(primes[i], primes[i + 1]) for i in range(len(primes) - 1)))

def sieve(n):
    A = [True] * (n + 1)
    for i in range(2, int(n ** 0.5) + 1):
        if A[i]:
            for j in range(i * i, n + 1, i):
                A[j] = False
    return [x for x in range(2, n + 1) if A[x]]

primes = sieve(int((5 * 10 ** 7) ** 0.5))
s = set()
for i in primes:
    for j in primes:
        for k in primes:
            n = i ** 2 + j ** 3 + k ** 4
            if n >= 5 * 10 ** 7: break
            s.add(n)
print len(s)

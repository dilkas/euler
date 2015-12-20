def sieve(m, n):
    prime = [True] * n
    for p in range(2, n):
        if not prime[p]: continue
        for t in range(p * p, n, p): prime[t] = False
    return [x for x in range(m, n) if prime[x]]

LIMIT = 10 ** 7
primes = sieve(10 ** 3, 10 ** 4) # a shameless guess
minRatio = float('inf')
for i in range(len(primes)):
    for j in range(i, len(primes)):
        n = primes[i] * primes[j]
        if n >= LIMIT: continue
        phi = (primes[i] - 1) * (primes[j] - 1)
        if sorted(str(n)) != sorted(str(phi)): continue
        ratio = float(n) / phi
        if ratio < minRatio:
            minRatio = ratio
            minN = n
print minN

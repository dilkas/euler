def prime(k, primes):
    for p in primes:
        if p > k ** 0.5: break
        if k % p == 0: return False
    return True

def update(primes, n):
    for k in range(primes[-1] + 1, n + 1):
        if prime(k, primes): primes.append(k)

def ways(n, start, primes):
    if n == 0: return 1
    if n < 0: return 0
    return sum(ways(n - primes[i], i, primes)
               for i in range(start, len(primes)))

primes = [2]
n = 1
while True:
    update(primes, n)
    if ways(n, 0, primes) > 5000: break
    n += 1
print n

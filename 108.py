import operator

primes = []

def trial_division(n):
    if n < 2: return {}
    prime_factors = {}
    for p in primes:
        if p * p > n: break
        while n % p == 0:
            prime_factors[p] = prime_factors.get(p, 0) + 1
            n /= p
    if n > 1:
        prime_factors[n] = 1
        primes.append(n)
    return prime_factors

def count_divisors(n):
    return reduce(operator.mul, map(lambda x: 2 * x + 1,
                                    trial_division(n).values()), 1)

n = 1
while (count_divisors(n) + 1) / 2 <= 1000:
    n += 1
print n

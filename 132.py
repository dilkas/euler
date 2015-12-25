K = 10 ** 9
HOW_MANY = 40

def prime(n, primes):
    for k in primes:
        if k > n ** 0.5: break
        if n % k == 0: return False
    return True

def next_prime(p, primes):
    n = p + 1
    while not prime(n, primes): n += 1
    primes.append(p)
    return n

primes = []
s = 0
p = 2
counter = 0
while counter < HOW_MANY and p <= K:
    if pow(10, K, 9 * p) == 1:
        s += p
        counter += 1
    p = next_prime(p, primes)
print(s)

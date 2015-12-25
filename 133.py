K = 10 ** 16

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

primes = [2, 3, 5]
s = 10
p = 7
while p < 10 ** 5:
    if pow(10, K, 9 * p) != 1: s += p
    p = next_prime(p, primes)
print(s)

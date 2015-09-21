import itertools

def fill_in(number, indices, d):
    if not indices:
        return [int(''.join(map(str, number)))] if number[0] else []
    l = []
    for v in range(10):
        if v == d: continue
        l += fill_in(number[:indices[0]] + [v] + number[indices[0] + 1:],
                     indices[1:], d)
    return l

def numbers(n, M, d):
    number = [d] * n
    l = []
    for indices in itertools.combinations(range(n), n - M):
        l += fill_in(number, indices, d)
    return l

def sieve(n):
    'Sieve of Eratosthenes'
    A = [True] * (n + 1)
    for i in range(2, int(n ** 0.5) + 1):
        if A[i]:
            for j in range(i ** 2, n + 1, i): A[j] = False
    return [i for i in range(2, n + 1) if A[i]]

def prime(n, primes):
    if n < 2: return False
    for p in primes:
        if n % p == 0: return False
    return True

n = 10
primes = sieve(int(10 ** (n / 2)))
total = 0
for d in range(10):
    for M in range(n, -1, -1):
        s = sum(number for number in numbers(n, M, d) if prime(number, primes))
        if s: break
    total += s
print(total)

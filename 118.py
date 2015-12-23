import itertools, math

def sieve_of_eratosthenes(n):
    A = [True] * (n + 1)
    A[1] = False
    for i in range(2, math.floor(n ** 0.5) + 1):
        if not A[i]: continue
        for j in range(i * i, n + 1, i): A[j] = False
    return A, [i for i in range(2, n + 1) if A[i]]

max_prime = math.floor(10 ** (9 / 2))
is_prime, primes = sieve_of_eratosthenes(max_prime)
memo = {}

def prime(n):
    if n <= max_prime: return is_prime[n]
    if n in memo: return memo[n]
    for k in primes:
        if n % k == 0:
            memo[n] = False
            return False
        if k > n ** 0.5:
            memo[n] = True
            return True
    memo[n] = True
    return True

def count(digits, previous):
    if len(digits) == 0: return 1
    s = 0
    n = 0
    for i in range(len(digits)):
        n = 10 * n + digits[i]
        if n > previous and prime(n):
            s += count(digits[i + 1:], n)
    return s

print(sum(count(permutation, 0)
         for permutation in itertools.permutations(range(1, 10))))

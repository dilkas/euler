import itertools, math

factorial = map(math.factorial, range(10))

def digits(n):
    return map(int, str(n))

def hash(n):
    return int(''.join(sorted(str(n), reverse=True)))

def next(n):
    return hash(sum(map(lambda x: factorial[x], digits(n))))

memo = {}
def length(n):
    if n in memo:
        if memo[n] == 0:
            memo[n] = -1
            return 0
        return memo[n]
    memo[n] = 0
    k = next(n)
    l = length(k) + 1
    if memo[n] == -1:
        while k != n:
            memo[k] = l
            k = next(k)
    memo[n] = l
    return memo[n]

def count(digits, n):
    s = str(n)
    zeros = s.count('0')
    res = factorial[digits - zeros] * (digits - zeros) ** zeros
    for i in '123456789':
        res /= s.count(i) or 1
    return int(res)

print sum(count(digits, n)
          for digits in range(2, 7)
          for n in map(lambda x: int(''.join(x)),
                       itertools.combinations_with_replacement('9876543210',
                                                               digits))
          if length(n) == 60)

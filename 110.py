import functools, math, operator

target = 8 * 10 ** 6
primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43]
min_n = functools.reduce(operator.mul, primes)
max_limit = 61

def number(powers):
    return functools.reduce(operator.mul, [p ** a for p, a in zip(primes, powers)])

def divisors(powers):
    return functools.reduce(operator.mul, map(lambda x: 2 * x + 1, powers))

def power_of_2(powers):
    return int(math.ceil((target / divisors(powers) - 1) / 2))

def recurse(powers, i):
    global min_n
    if number(powers) > min_n: return
    if divisors(powers) > target:
        min_n = min(min_n, number(powers))
        return
    if power_of_2(powers) < 0: return
    if i == len(powers):
        powers[0] = power_of_2(powers)
        if powers[0] < powers[1]: return
        min_n = min(min_n, number(powers))
        return
    limit = max_limit if i == 1 else powers[i - 1] + 1
    for v in range(limit):
        recurse(powers[:i] + [v] + powers[i + 1:], i + 1)

powers = [0] * len(primes)
recurse(powers, 1)
print(min_n)

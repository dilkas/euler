import math

limit = 120000

rad = [1] * limit
for i in range(2, limit):
    if rad[i] != 1: continue
    for j in range(i, limit, i): rad[j] *= i

pairs = sorted((rad[i], i) for i in range(1, limit))

s = 0
for c in range(3, limit):
    for rad_a, a in pairs:
        if 2 * rad_a * rad[c] >= c: break
        b = c - a
        if a < b and math.gcd(a, b) == 1 and rad_a * rad[b] * rad[c] < c:
            s += c
print(s)

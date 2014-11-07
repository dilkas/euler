def c(r, n):
    c = 1
    for i in range(r + 1, n + 1): c *= i
    delta = n - r
    for i in range(1, delta + 1): c /= i
    return c
count = 0
for n in range(23, 101):
    for r in range(1, n + 1):
        if c(r, n) > 1000000: count += 1
print count

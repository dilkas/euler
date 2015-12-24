import math

limit = 10 ** 8
s = set()
for a in range(1, math.ceil((limit // 2) ** 0.5)):
    n = a * a + (a + 1) ** 2
    b = a + 2
    while n < limit:
        if str(n) == str(n)[::-1]: s.add(n)
        n += b * b
        b += 1
print(sum(s))

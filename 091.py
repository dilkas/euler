def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a

MAX = 50
count = 0
for x in range(1, MAX + 1):
    for y in range(1, MAX + 1):
        g = gcd(x, y)
        dx = y / g
        dy = x / g
        count += min((MAX - x) / dx, y / dy) + min((MAX - y) / dy, x / dx)
print count + 3 * MAX ** 2

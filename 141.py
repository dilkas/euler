def gcd(a, b):
    "Euclidean algorithm"
    while b != 0: a, b = b, a % b
    return a

LIMIT = 10 ** 12
s = 0
for a in range(2, int(LIMIT ** (1/3))):
    a3 = a ** 3
    for b in range(1, a):
        if gcd(a, b) > 1: continue
        a3b = a3 * b
        b2 = b * b
        if a3b + b2 >= LIMIT: break
        c = 1
        while True:
            n = a3b * c * c + b2 * c
            if n >= LIMIT: break
            root = n ** 0.5
            if (root == int(root)): s += n
            c += 1
print(s)

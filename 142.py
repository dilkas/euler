import sys

def perfect_square(n):
    return (n ** 0.5).is_integer()

a = 5
while True:
    a2 = a * a
    for c in range(4, a):
        c2 = c * c
        if not perfect_square(a2 - c2): continue
        min_d = int((a2 - c2) ** 0.5) + 1
        if min_d % 2 != c % 2: min_d += 1
        for d in range(min_d, c, 2):
            d2 = d * d
            if perfect_square(a2 - d2) and perfect_square(c2 - a2 + d2):
                print((2 * a2 + c2 - d2) // 2)
                sys.exit()
    a += 1

import math

phi = (1 + 5 ** 0.5) / 2

def pandigital(n):
    s = sorted(str(n))
    return len(s) == 9 and all(s[i] == str(i + 1)
                               for i in range(9))

def first(k):
    t = k * math.log10(phi) - math.log10(5 ** 0.5)
    return pandigital(int(10 ** (t - int(t) + 8)))

f1 = 1
f2 = 1
k = 2
while not (pandigital(f2) and first(k)):
    f2, f1 = (f1 + f2) % (10 ** 9), f2
    k += 1
print k

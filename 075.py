import collections, math

def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a

LMax = 1500000
counts = collections.defaultdict(int)

for m in range(1, int(math.sqrt(LMax / 2))):
    for n in range(1, m):
        if (m + n) % 2 == 0 or gcd(n, m) != 1: continue
        k = 1
        while True:
            L = 2 * m * k * (m + n)
            if L > LMax: break
            counts[L] += 1
            k += 1

count = 0
for L in counts:
    if counts[L] == 1: count += 1
print count
    

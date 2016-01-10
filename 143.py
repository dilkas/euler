LIMIT = 120000

def gcd(a, b):
    "Euclidean algorithm"
    while b != 0: a, b = b, a % b
    return a

# generating all viable pairs
pairs = set()
for u in range(1, int(LIMIT ** 0.5) + 1):
    for v in range(1, u):
        if (u - v) % 3 == 0 or gcd(u, v) != 1: continue
        p = 2 * u * v + v * v
        r = u * u - v * v
        p, r = sorted((p, r))
        x = p
        y = r
        while x + y <= LIMIT:
            pairs.add((x, y))
            x += p
            y += r

pairs = sorted(pairs)[1:] # removing the pair (3, 5) which somehow creeps in
index = {}
for i, pair in enumerate(pairs):
    if pair[0] not in index: index[pair[0]] = i

sums = set()
for a, b in pairs:
    if b not in index: continue
    i = index[a]
    j = index[b]
    while (i < len(pairs) and j < len(pairs) and
           pairs[i][0] == a and pairs[j][0] == b):
        if pairs[i][1] == pairs[j][1]:
            s = a + b + pairs[i][1]
            if s <= LIMIT: sums.add(s)
            i += 1
            j += 1
        elif pairs[i][1] < pairs[j][1]:
            i += 1
        else:
            j += 1
print(sum(sums))

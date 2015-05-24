pentagonal = sum([[i * (3 * i - 1) / 2, i * (3 * i - 1) / 2 + i] for i in range(1, 250)], [])
p = [1]
sign = [1, 1, -1, -1]
n = 0
while p[n] > 0:
    n += 1
    px, i = 0, 0
    while pentagonal[i] <= n:
        px += p[n - pentagonal[i]] * sign[i % 4]
        i += 1
    p.append(px % 1000000)
print n

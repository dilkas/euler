LIMIT = 10 ** 6
solutions = {}
for v in range(1, LIMIT):
    for u in range(1, 3 * v):
        n = u * v
        if n >= LIMIT: break
        if (u + v) % 4 == 0 and (3 * v - u) % 4 == 0:
            solutions[n] = solutions.get(n, 0) + 1

count = 0
for n in solutions:
    if solutions[n] == 10: count += 1
print(count)

LIMIT = 10 ** 14 # increase until we get at least 30 nuggets
nuggets = set()
for x, y in [(166, 37), (26, -5), (34, -7), (86, 19), (16, 2), (16, -2)]:
    while (True):
        if x > LIMIT: break
        if x % 10 == 4: nuggets.add((x - 14) // 10)
        x, y = 9 * x + 40 * y, 2 * x + 9 * y
print(sum(sorted(nuggets)[:30]))

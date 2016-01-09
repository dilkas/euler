LIMIT = 100 * 10 ** 6
count = 0
x = y = 1
while x + y < LIMIT:
    x, y = 3 * x + 4 * y, 2 * x + 3 * y
    count += LIMIT // (x + y)
print(count)

x = 2
y = 1
s = 0
while x <= 10 ** 9 / 2 + 1:
    if (2 * x + 1) % 3 == 0 and ((x + 2) * y) % 3 == 0 and 2 * x + 2 <= 10 ** 9:
        s += 2 * x + 2
    if ((2 * x - 1) % 3 == 0 and x - 2 > 0 and ((x - 2) * y) % 3 == 0 and
        2 * x - 2 <= 10 ** 9):
        s += 2 * x - 2
    x, y = 2 * x + 3 * y, 2 * y + x
print s

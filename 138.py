x = 0
L = 1
s = 0
for _ in range(12):
    x, L = -9 * x - 4 * L - 4, -20 * x - 9 * L - 8
    s += abs(L)
print(s)

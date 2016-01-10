s = 0
for n in range(1, 10):
    if n % 2 == 0:
        s += 20 * 30 ** (n // 2 - 1)
    elif n % 4 == 3:
        s += 100 * 500 ** ((n - 3) // 4)
print(s)

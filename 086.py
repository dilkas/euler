M = 100
count = 2060
while count <= 10 ** 6:
    M += 1
    for s in range(2, 2 * M + 1):
        if ((M ** 2 + s ** 2) ** 0.5).is_integer():
            count += min(M, s - 1) - (s + 1) / 2 + 1
print M

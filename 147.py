def count_rectangles(n, m):
    n, m = min(n, m), max(n, m)
    return (m * (m + 1) * n * (n + 1) / 4 +
            n * ((2 * m - n) * (4 * n * n - 1) - 3) / 6)

print(int(sum(count_rectangles(n, m) for n in range(1, 48)
              for m in range(1, 44))))

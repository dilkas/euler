memo = {}

def F(m, n):
    if (m, n) in memo: return memo[(m, n)]
    s = 1
    if n >= m:
        s += sum(F(m, n - start - size - 1)
                 for size in range(m, n + 1)
                 for start in range(n - size + 1))
    memo[(m, n)] = s
    return s

m = n = 50
while F(m, n) <= 10 ** 6: n += 1
print(n)

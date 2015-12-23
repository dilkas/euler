memo = {}

def F(size, n):
    if (size, n) in memo: return memo[(size, n)]
    s = 1
    if n >= size:
        s += sum(F(size, n - start - size) for start in range(n - size + 1))
    memo[(size, n)] = s
    return s

print(F(2, 50) + F(3, 50) + F(4, 50) - 3)

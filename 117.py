sizes = [2, 3, 4]
memo = {}

def F(n):
    if n in memo: return memo[n]
    s = 1
    if n >= min(sizes):
        s += sum(F(n - start - size)
                 for size in sizes
                 for start in range(n - size + 1))
    memo[n] = s
    return s

print(F(50))

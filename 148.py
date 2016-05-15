def triangle(n):
    return n * (n + 1) // 2

N = 10 ** 9
D = 7

# convert N to base D
digits = []
while N:
    digits.append(N % D)
    N //= D

multiplier = 1
s = 0
for i in range(len(digits) - 1, -1, -1):
    s += multiplier * triangle(digits[i]) * triangle(D) ** i
    multiplier *= digits[i] + 1
print(s)

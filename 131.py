import math

def prime(n):
    for k in range(2, math.floor(n ** 0.5) + 1):
        if n % k == 0: return False
    return True

count = 0
for i in range(1, 577):
    if prime((i + 1) ** 3 - i ** 3): count += 1
print(count)

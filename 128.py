import math

target = 2000

def prime(n):
    for k in range(2, math.floor(n ** 0.5) + 1):
        if n % k == 0: return False
    return True

n = 1
counter = 0
while True:
    if prime(6 * n - 1) and prime(6 * n + 1) and prime(12 * n + 5):
        counter += 1
    if counter == target:
        print(3 * n * n - 3 * n + 2)
        break
    if prime(6 * n - 1) and prime(6 * n + 5) and prime(12 * n - 7):
        counter += 1
    if counter == target:
        print(3 * n * n + 3 * n + 1)
        break
    n += 1

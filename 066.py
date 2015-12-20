import math

def generateA(S):
    m = 0
    d = 1
    a = int(math.floor(S ** 0.5))
    while True:
        yield a
        m = d * a - m
        d = int((S - m ** 2) / d)
        a = int(math.floor((S ** 0.5 + m) / d))

def solution(D, x, y):
    return x ** 2 - D * y ** 2 == 1

maxN = 0
for D in range(2, 1001):
    if (D ** 0.5).is_integer(): continue
    generator = generateA(D)
    n2 = 1
    n1 = next(generator)
    d2 = 0
    d1 = 1
    while True:
        a = next(generator)
        n = a * n1 + n2
        d = a * d1 + d2
        n2 = n1
        n1 = n
        d2 = d1
        d1 = d
        if solution(D, n, d):
            if n > maxN:
                maxN = n
                maxD = D
            break
print maxD

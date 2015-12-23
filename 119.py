import heapq, math

def digit_sum(n):
    s = 0
    while n > 0:
        s += n % 10
        n //= 10
    return s

a = []
max_e = 64 # consider all numbers < 2 ** 64
b = 2
while True:
    e = (math.ceil(b / (9 * math.log10(b))) if b >= 10 else
         math.ceil(math.log(10, b))) # clever math
    if e >= max_e: break
    n = b ** e
    while n < 2 ** max_e:
        if digit_sum(n) == b: heapq.heappush(a, n)
        n *= b
    b += 1
print(heapq.nsmallest(30, a)[-1])

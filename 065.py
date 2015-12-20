def sumOfDigits(n):
    s = 0
    while n > 0:
        s += n % 10
        n /= 10
    return s

numerator2 = 2
numerator1 = 3
even = 2
for i in range(98):
    if i % 3 == 0:
        a = even
        even += 2
    else:
        a = 1
    numerator = a * numerator1 + numerator2
    numerator2 = numerator1
    numerator1 = numerator
print sumOfDigits(numerator)

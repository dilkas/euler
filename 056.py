def digitSum(n):
    return sum(int(c) for c in str(n))

maxDigitSum = 0
for a in range(1, 100):
    for b in range(1, 100):
        currentDigitSum = digitSum(a ** b)
        if currentDigitSum > maxDigitSum: maxDigitSum = currentDigitSum
print maxDigitSum

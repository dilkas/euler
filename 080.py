def digitalSum(n):
    a = 5 * n
    b = 5
    while b < 10 ** 101:
        if a >= b:
            a -= b
            b += 10
        else:
            a *= 100
            b = (b - 5) * 10 + 5
    s = str(b)
    return sum(int(s[i]) for i in range(100))

print sum(digitalSum(n)
          for n in range(1, 101)
          if n not in [x ** 2 for x in range(1, 11)])

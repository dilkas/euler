a = 1
for i in range(1, 101): a *= i
print sum(map(int, str(a)))

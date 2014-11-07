import math
suma = 0
for number in range(3, 100000):
  if sum(math.factorial(int(digit)) for digit in str(number)) == number:
    suma += number
print suma

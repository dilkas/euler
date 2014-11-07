suma = 0
for number in range(2, 10000):
  if sum(int(digit)**5 for digit in str(number)) == number:
    suma += number
print suma

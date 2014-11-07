def binary(n):
  bin = ''
  while n > 0:
    bin += str(n % 2)
    n = n >> 1
  return bin
suma = 0
for number in range(1, 1000000):
  if str(number) == str(number)[::-1] and binary(number) == binary(number)[::-1]:
    suma += number
print suma

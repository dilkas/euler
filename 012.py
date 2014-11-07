import sys
def prime(number):
  for divisor in range(2, number):
    if number % divisor == 0:
      return 0
  return 1
def factor(number):
  divisors = {}
  divisor = 2
  result = 1
  while divisor <= number:
    if number % divisor == 0 and prime(divisor):
      number = number / divisor
      if divisor in divisors.keys():
        divisors[divisor] += 1
      else:
        divisors[divisor] = 1
      divisor -= 1
    divisor += 1
  for power in divisors.values():
    result *= power + 1
  return result
def triangle(index):
  return sum(range(index + 1))
index = 1
while True:
  if factor(triangle(index)) > 500:
    print triangle(index)
    sys.exit()
  index += 1

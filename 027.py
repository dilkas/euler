import math
def prime(number):
  if number <= 0:
    return 0
  for divisor in range(2, int(math.floor(math.sqrt(number))) + 1):
    if number % divisor == 0:
      return 0
  return 1
def produced(a, b):
  total = 0
  for n in range(0, 100):
    if prime(n ** 2 + a * n + b):
      total += 1
    else:
      break
  return total
max = 0
for a in range(-999, 1000):
  for b in range(-999, 1000):
    if produced(a, b) > max:
      max = produced(a, b)
      x = a
      y = b
print x * y
print max

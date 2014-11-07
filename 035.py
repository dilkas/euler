import math
def prime(number):
  for i in range(2, math.sqrt(number) + 1):
    if number % i == 0:
      return 0
  return 1
def circularPrime(number):
  for i in range(len(str(number))):
    number = int(str(number)[1:] + str(number)[0])
    if not prime(number):
      return 0
  return 1
count = 0
for i in range(2, 1000000):
  if ("0" not in str(i) and circularPrime(i)):
    count += 1
print count

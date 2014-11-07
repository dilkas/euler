import math

def prime(number):
  if number == '': return True
  else:
    number = int(number)
    if number <= 1: return False
    for divisor in range(2, int(math.floor(math.sqrt(number))) + 1):
      if number % divisor == 0: return False
    return True

def truncable(number):
  for iterator in range(len(str(number))):
    if not prime(str(number)[iterator:]) or not prime(str(number)[:-iterator]):
      return False
  return True

count = 0
number = 10
suma = 0
while count < 11:
  if truncable(number):
    count += 1
    suma += number
  number += 1
print suma

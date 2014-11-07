abc = ["a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"]
file = open("names.txt", 'r')
names = sorted(list(set(file.read().rstrip().split('","'))))
summ = 0
for name in names:
  summ += sum(abc.index(letter.lower()) + 1 for letter in name) * (names.index(name.upper()) + 1)
print summ

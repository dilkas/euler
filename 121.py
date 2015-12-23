import math

turns = 15
row = [1]
for n in range(1, turns + 1):
    length = len(row)
    new_row = [0] * (length + 1)
    for i in range(length):
        new_row[i] += row[i]
        new_row[i + 1] += n * row[i]
    row = new_row
print((int)(1 // (sum(row[:len(row) // 2]) / math.factorial(turns + 1))))

f = open('p082_matrix.txt', 'r')
matrix = []
for line in f.readlines(): matrix.append(map(int, line.split(',')))
f.close()

sums = []
for i in range(80): sums.append([0] * 80)
for i in range(80): sums[i][79] = matrix[i][79]

for j in range(78, -1, -1):
    sums[0][j] = sums[0][j + 1] + matrix[0][j]
    for i in range(1, 80):
        sums[i][j] = min(sums[i - 1][j], sums[i][j + 1]) + matrix[i][j]
    for i in range(78, -1, -1):
        sums[i][j] = min(sums[i + 1][j] + matrix[i][j], sums[i][j])

print min(sums[x][0] for x in range(80))

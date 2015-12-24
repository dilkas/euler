max_n = 100000
rad = [1] * (max_n + 1)
for i in range(2, max_n + 1):
    if rad[i] != 1: continue
    for j in range(i, max_n + 1, i): rad[j] *= i
print(sorted((rad[n], n) for n in range(2, max_n + 1))[9998][1])

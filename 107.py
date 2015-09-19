def sum_row(r, f):
    return 

f = open('p107_network.txt')
weight = [map(lambda x: x[0] if x[0] == '-' else int(x), line.split(','))
          for line in f]
f.close()
graphsize = 40

distance = [float('inf')] * graphsize
intree = [False] * graphsize
source = [None] * graphsize

treesize = 1
treecost = 0
intree[0] = True
for j in range(graphsize):
    if weight[0][j] != '-':
        distance[j] = weight[0][j]
        source[j] = 0

while treesize < graphsize:
    i = min(filter(lambda x: not intree[x], range(graphsize)),
            key=lambda x: distance[x])

    treesize += 1
    treecost += distance[i]
    intree[i] = True

    for j in range(graphsize):
        if weight[i][j] != '-' and distance[j] > weight[i][j]:
            distance[j] = weight[i][j]
            source[j] = i

print sum(map(lambda r: sum(filter(lambda x: x != '-', r)), weight)) / 2 - treecost

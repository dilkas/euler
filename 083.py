import Queue

f = open('p083_matrix.txt')
matrix = [map(int, x.split(',')) for x in f.readlines()]
f.close()

dist = [[float('inf')] * 80 for x in range(80)]
dist[0][0] = matrix[0][0]

Q = Queue.PriorityQueue()
Q.put((matrix[0][0], 0, 0))

while not Q.empty():
    u = Q.get()
    for v in [[u[i] + d[i] for i in range(3)]
              for d in [(0, 1, 0), (0, 0, 1), (0, -1, 0), (0, 0, -1)]]:
        if any(v[i] < 0 or v[i] >= 80 for i in [1, 2]): continue
        alt = dist[u[1]][u[2]] + matrix[v[1]][v[2]]
        if alt < dist[v[1]][v[2]]:
            dist[v[1]][v[2]] = alt
            Q.put((alt, v[1], v[2]))
print dist[-1][-1]

LIMIT = 10 ** 6 + 1

def travel(i, sums, visited, path = []):
    if i >= LIMIT: return []
    if i in path: return path[path.index(i):]
    visited[i] = True
    return travel(sums[i], sums, visited, path + [i])

sums = [0] * LIMIT
for i in range(1, LIMIT):
    for j in range(2 * i, LIMIT, i):
        sums[j] += i

visited = [False] * LIMIT
print min(max((travel(i, sums, visited) for i in range(1, LIMIT)
               if not visited[i]), key=len))

import math

max_k = 200
m = [math.inf] * max_k

def traverse(path):
    m_k = len(path) - 1
    i = path[-1] - 1
    if path[-1] > max_k or m_k > m[i]: return
    m[i] = m_k
    for i in range(len(path) - 1, -1, -1):
        traverse(path + [path[-1] + path[i]])

traverse([1])
print(sum(m))

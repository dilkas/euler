def area(a, b, c):
    return abs((a[0] - c[0]) * (b[1] - a[1]) - (a[0] - b[0]) * (c[1] - a[1]))

f = open('p102_triangles.txt')
count = 0
for line in f:
    coordinates = map(int, line.split(','))
    a = coordinates[:2]
    b = coordinates[2:4]
    c = coordinates[4:]
    o = [0, 0]
    if area(a, b, c) == area(a, b, o) + area(a, o, c) + area(o, b, c):
        count += 1
f.close()
print count

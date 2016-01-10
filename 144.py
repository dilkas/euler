def equal(a, b):
    return abs(a - b) <= 0.001

x0 = 0
y0 = 10.1
x = 1.4
y = -9.6
count = 0
while not (-0.01 <= x <= 0.01 and equal(y, 10)):
    m0 = (y - y0) / (x - x0)
    m1 = -4 * x / y
    t = (m0 - m1) / (1 + m0 * m1)
    c = (m1 - t) / (1 + t * m1)
    d = y - c * x
    D = 400 * c * c - 16 * d * d + 1600
    x1 = (-2 * c * d + D ** 0.5) / (2 * c * c + 8)
    x2 = (-2 * c * d - D ** 0.5) / (2 * c * c + 8)
    x0 = x
    y0 = y
    x = x2 if equal(x, x1) else x1
    y = c * x + d
    count += 1
print(count)

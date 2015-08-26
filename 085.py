target = 2 * 10 ** 6
x = 1000
y = 1
closest_count = 0
while x >= y:
    area = x * y
    count = area * (x + 1) * (y + 1) / 4
    if abs(target - count) < abs(target - closest_count):
        closest_count = count
        closest_area = area
    if count > target: x -= 1
    else: y += 1
print closest_area

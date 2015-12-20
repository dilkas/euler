def bouncy(n):
    s = str(n)
    increasing = False
    decreasing = False
    for i in range(len(s) - 1):
        if s[i + 1] > s[i]: increasing = True
        if s[i + 1] < s[i]: decreasing = True
        if increasing and decreasing: return True
    return False

proportion = 0.99
bouncy_count = 0
n = 1
while True:
    if bouncy(n): bouncy_count += 1
    if bouncy_count / n >= proportion:
        print(n)
        break
    n += 1

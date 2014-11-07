temp = 28433
for i in range(7830457):
    temp *= 2
    if (len(str(temp)) > 10): temp = int(str(temp)[-10:])
print temp + 1

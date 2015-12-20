import math

def second_rule(s):
    start = s[0]
    end = 0
    for i in range(int(math.ceil(len(s) / 2.))):
        start += s[i]
        end += s[-i]
        if start <= end: return False
    return True

def first_rule(s):
    powerset = [[]]
    for x in s:
        powerset += [subset + [x] for subset in powerset]
    return len(set(map(sum, powerset))) == 2 ** len(s)

f = open('p105_sets.txt')
total = 0
for line in f:
    s = sorted(map(int, line.split(',')))
    if second_rule(s) and first_rule(s): total += sum(s)
f.close()
print total

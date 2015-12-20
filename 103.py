guess = [20, 31, 38, 39, 40, 42, 45]
delta = 3

def generate_sets(s=[]):
    i = len(s)
    if i >= 7: return [s]
    sets = []
    for n in range(guess[i] - delta, guess[i] + delta + 1):
        sets += generate_sets(s + [n])
    return sets

def second_rule(s):
    start = s[0]
    end = 0
    for i in range(1, 4):
        start += s[i]
        end += s[-i]
        if start <= end: return False
    return True

def first_rule(s):
    powerset = [[]]
    for x in s:
        powerset += [subset + [x] for subset in powerset]
    return len(set(map(sum, powerset))) == 2 ** 7

sets = sorted(generate_sets(), key=sum)
for s in sets:
    if second_rule(s) and first_rule(s):
        print ''.join(map(str, s))
        break

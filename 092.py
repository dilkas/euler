from string import digits
def fac(n, memo={}):
    if not n in memo:
        f, m = 1, n
        while m:
            f, m = f*m, m-1
        memo[n] = f
    return memo[n]


def nondec_num_iter(digits, minnum = 0, so_far = ''):
    if not digits:
        yield so_far
        return
    for i in range(minnum, 10):
        for s in nondec_num_iter(digits-1, i, so_far + str(i)):
            yield s


count = 0
unhappy = {0:0, 1:0, 89:1}
for i in nondec_num_iter(7):
    xs = [int(i)]
    while not xs[-1] in unhappy:
        x = sum([int(y)*int(y) for y in str(xs[-1])])
        xs.append(x)
    for x in xs:
        unhappy[x] = unhappy[xs[-1]] 
    if unhappy[int(i)]:
        prod = 1
        for j in digits:
            prod *= fac(i.count(j))
        count += fac(7) / prod
print count

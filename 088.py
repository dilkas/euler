import math

MAX_K = 12000

def generate(l, original_product, db):
    if len(l) > int(math.log(2 * MAX_K, 2)): return
    k = len(l) - sum(l) + original_product
    if 2 <= k <= MAX_K: db[k] = min(db[k], original_product)
    n = l[-1] if l else 2
    while True:
        product = original_product * n
        if product > 2 * MAX_K: return
        generate(l + [n], product, db)
        n += 1

db = [2 * k for k in range(MAX_K + 1)]
generate([], 1, db)
print sum(set(db[2:]))

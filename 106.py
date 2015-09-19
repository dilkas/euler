def choose(n, k):
    if k == n: return 1
    k = min(k, n - k)
    c = 1
    for i in range(k):
        c *= (n - i) / (i + 1.)
    return int(c)

n = 12
print sum(int(choose(n, s) * choose(n - s, s) / 2.
              - choose(2 * s, s) / (s + 1.) * choose(n, 2 * s))
          for s in range(2, 7))

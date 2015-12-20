doubles = range(2, 41, 2) + [50]
scores = range(21) + [25] + doubles + range(3, 61, 3)
print sum(1 for i, first in enumerate(scores) for second in scores[:i + 1]
          for third in doubles if first + second + third < 100)

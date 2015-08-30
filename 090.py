import itertools

print sum(1 for dice in
          itertools.combinations(itertools.combinations(range(9) + [6], 6), 2)
          if all((numbers[0] in dice[0] and numbers[1] in dice[1]) or
                 (numbers[0] in dice[1] and numbers[1] in dice[0]) for numbers in
                 [(0, 1), (0, 4), (0, 6), (1, 6),
                  (1, 8), (2, 5), (3, 6), (4, 6)]))

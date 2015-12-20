import copy

def square_range(i):
    return range(i - i % 3, i - i % 3 + 3)

def neighbours(I, J):
    return ([(I, j) for j in range(9)] + [(i, J) for i in range(9)] +
            [(i, j) for i in square_range(I) for j in square_range(J)])

def insert(grid, I, J, value):
    grid[I][J] = value
    for i, j in neighbours(I, J):
        if not isinstance(grid[i][j], set): continue
        grid[i][j].discard(value)
        if len(grid[i][j]) == 0: return True
    return False

def min_set(grid):
    min_i = -1
    min_j = -1
    for i in range(9):
        for j in range(9):
            if (isinstance(grid[i][j], set) and
                (min_i == -1 or len(grid[i][j]) < len(grid[min_i][min_j]))):
                min_i = i
                min_j = j
    return min_i, min_j

def search(grid):
    while True:
        made_changes = False
        found_sets = False
        for i in range(9):
            for j in range(9):
                if isinstance(grid[i][j], set):
                    found_sets = True
                    if len(grid[i][j]) == 1:
                        made_changes = True
                        if insert(grid, i, j, grid[i][j].pop()): return 0
        if not found_sets: return int(''.join(map(str, grid[0][:3])))
        if not made_changes: break
    i, j = min_set(grid)
    for digit in grid[i][j]:
        new_grid = copy.deepcopy(grid)
        if insert(new_grid, i, j, digit): continue
        s = search(new_grid)
        if s > 0: return s
    return 0

def initialize(grid):
    new_grid = copy.deepcopy(grid)
    for i in range(9):
        for j in range(9):
            if grid[i][j] == 0:
                new_grid[i][j] = (set(range(1, 10)) -
                                  set(grid[I][J] for I, J in neighbours(i, j)))
    return new_grid

def parse_grid(f):
    f.readline()
    grid = []
    for _ in range(9):
        line = f.readline()
        if line[-1] == '\n': line = line[:-1]
        grid.append(map(int, line))
    return initialize(grid)

def parse_grids(filename):
    f = open(filename)
    grids = [parse_grid(f) for _ in range(50)]
    f.close()
    return grids

print sum(search(grid) for grid in parse_grids('p096_sudoku.txt'))

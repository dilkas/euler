N = 2000

# generate all numbers as a 1-dimensional list
NUMBERS = []
for k in range(1, 56):
    NUMBERS.append((100003 - 200003 * k + 300007 * k ** 3) % 1000000 - 500000)
for k in range(55, 4000000):
    NUMBERS.append((NUMBERS[k - 24] + NUMBERS[k - 55] + 1000000) % 1000000 -
                   500000)

def kadane(i, direction, condition):
    """Kadane's algorithm starting at position i, stepping forward by direction
    while condition is true."""
    m = current = NUMBERS[i]
    while condition(i):
        i += direction
        current = max(current + NUMBERS[i], NUMBERS[i])
        m = max(m, current)
    return m

def one_direction(positions, direction, condition):
    """Runs Kadane's algorithm for every starting position in positions."""
    return max(kadane(i, direction, condition) for i in positions)

def not_last_column(i):
    '''Condition: we can move to the right if we are not in the last column.'''
    return i % N != N - 1

def not_last_row(i):
    '''Condition: we can move down if we are not in the last row.'''
    return i // N != N - 1

left_column = set(range(0, N * N, N))
top_row = set(range(N))
print(max(one_direction(left_column, 1, not_last_column),
          one_direction(top_row, N, not_last_row),
          one_direction(top_row | left_column, N + 1,
                        lambda i: not_last_column(i) and not_last_row(i)),
          one_direction(top_row | set(range(N - 1, N * N, N)), N - 1,
                        lambda i: not_last_row(i) and i % N != 0)))

min_length = 3
row_length = 50
memo = {}

def count_ways(length):
    if length in memo: return memo[length]
    result = 1 # the possibility of not doing anything
    if length >= min_length:
        result += sum(count_ways(length - start - size - 1)
                      for size in range(min_length, length + 1)
                      for start in range(length - size + 1))
    memo[length] = result
    return result

print(count_ways(50))

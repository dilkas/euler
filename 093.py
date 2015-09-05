import itertools, operator

def expressions(digits, signs):
    # in reverse Polish notation
    patterns = ['ddsddss', 'ddsdsds', 'dddsdss', 'ddddsss']
    all_expressions = []
    for pattern in patterns:
        expression = []
        digits_i = 0
        signs_i = 0
        for symbol in pattern:
            if symbol == 'd':
                expression.append(digits[digits_i])
                digits_i += 1
            else:
                expression.append(signs[signs_i])
                signs_i += 1
        all_expressions.append(expression)
    return all_expressions

def evaluate(expression):
    stack = []
    for x in expression:
        if isinstance(x, (int, float)):
            stack.append(x)
        else:
            b = stack.pop()
            a = stack.pop()
            try:
                stack.append(x(a, b))
            except ZeroDivisionError:
                return 0
    return stack[0]

operators = [operator.add, operator.sub, operator.mul, operator.truediv]
all_signs = set(permutation for combination in
                itertools.combinations_with_replacement(operators, 3)
                for permutation in itertools.permutations(combination))
max_n = 0
for digits in itertools.combinations(range(10), 4):
    s = set(evaluate(expression)
            for permutation in itertools.permutations(digits)
            for signs in all_signs
            for expression in expressions(permutation, signs))
    n = 1
    while n in s: n += 1
    if n > max_n:
        max_n = n
        max_digits = digits
print(''.join(map(str, max_digits)))

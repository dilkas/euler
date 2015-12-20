import collections

def fit(word, number):
    mapping = {}
    used_digits = set()
    for character, digit in zip(word, str(number)):
        if character in mapping:
            if mapping[character] != digit: return False
        else:
            if digit in used_digits: return False
            mapping[character] = digit
            used_digits.add(digit)
    return mapping

f = open('p098_words.txt')
anagrams = collections.defaultdict(lambda: collections.defaultdict(list))
max_len = 0
for word in f.read()[1:-1].split('","'):
    l = len(word)
    anagrams[l][''.join(sorted(word))].append(word)
    if l > max_len: max_len = l
f.close()

square_numbers = [[] for _ in range(max_len + 1)]
n = 1
while True:
    n_sq = n ** 2
    l = len(str(n_sq))
    if l > max_len: break
    square_numbers[l].append(n_sq)
    n += 1

for length in range(max_len, 0, -1):
    max_number = 0
    for letters in anagrams[length]:
        if len(anagrams[length][letters]) < 2: continue
        for word1 in anagrams[length][letters]:
            for number in square_numbers[length][::-1]:
                mapping = fit(word1, number)
                if not mapping: continue
                for word2 in anagrams[length][letters]:
                    if word2 == word1: continue
                    if mapping[word2[0]] == '0': continue
                    new_number = int(''.join(mapping[c] for c in word2))
                    if (new_number ** 0.5).is_integer():
                        max_number = max(max_number, number, new_number)
    if max_number:
        print max_number
        break

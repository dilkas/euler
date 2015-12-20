import random, time

def nearest_company(square, companies):
    for company in companies:
        if company > square:
            return company
    return companies[0]

def draw_card(square, cards):
    card = cards.pop(0)
    railway = [5, 15, 25, 35]
    utility = [12, 28]
    if card == 'R':
        square = nearest_company(square, railway)
    elif card == 'U':
        square = nearest_company(square, utility)
    elif card == -3:
        square -= 3
    elif card:
        square = card
    cards.append(card)
    return square

start_time = time.time()
square = 0
doubles_count = 0
frequencies = [0] * 40

CC_cards = [None] * 14 + [0, 10]
random.shuffle(CC_cards)

CH_cards = [None] * 6 + [0, 10, 11, 24, 39, 5, 'R', 'R', 'U', -3]
random.shuffle(CH_cards)

while time.time() - start_time < 30:
    dice = [random.randint(1, 4) for x in range(2)]
    if dice[0] != dice[1]: doubles_count = 0
    else: doubles_count += 1
    if doubles_count >= 3:
        square = 10
    else:
        square = (square + sum(dice)) % 40
        if square == 30: # G2J
            square = 10
        elif square in [2, 17, 33]: # CC
            square = draw_card(square, CC_cards)
        elif square in [7, 12, 36]: # CH
            square = draw_card(square, CH_cards)
    frequencies[square] += 1

popular = [0] * 3
for i in range(40):
    for j in range(3):
        if frequencies[i] > frequencies[popular[j]]:
            for k in range(2, j, -1):
                popular[k] = popular[k - 1]
            popular[j] = i
            break

print ''.join(map(str, popular))

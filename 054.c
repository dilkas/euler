#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define N_CARDS_IN_HAND 5
#define SPADES 'S'
#define HEARTS 'H'
#define DIAMONDS 'D'
#define CLUBS 'C'
#define VALUES_COUNT 13
#define TWO_CARDS 2
#define THREE_CARDS 3
#define FOUR_CARDS 4
#define FILENAME "poker.txt"
#define READ "r"
#define LINE_LENGTH 31
#define ONE_PLAYER_LINE_LENGTH 14
#define SPACE " "
#define TWO_CHARS 2
#define TEN_CHAR 'T'
#define JACK_CHAR 'J'
#define QUEEN_CHAR 'Q'
#define KING_CHAR 'K'
#define ACE_CHAR 'A'
#define DELTA_VALUES 2
enum value_type {
  EMPTY = -1,
  TWO,
  THREE,
  FOUR,
  FIVE,
  SIX,
  SEVEN,
  EIGHT,
  NINE,
  TEN,
  JACK,
  QUEEN,
  KING,
  ACE
};
enum rank_type {
  HIGH_CARD,
  ONE_PAIR,
  TWO_PAIRS,
  THREE_OF_A_KIND,
  STRAIGHT,
  FLUSH,
  FULL_HOUSE,
  FOUR_OF_A_KIND,
  STRAIGHT_FLUSH,
  ROYAL_FLUSH,
  NONE
};
struct card {
  enum value_type value;
  char suite;
};
struct rank {
  enum rank_type type;
  enum value_type value1;
  enum value_type value2;
};


struct rank init_rank() {
  struct rank rank;
  rank.type = NONE;
  rank.value1 = EMPTY;
  rank.value2 = EMPTY;
  return rank;
}


int* count_values(struct card* hand) {
  int* values = malloc(VALUES_COUNT * sizeof(int));
  int i;
  for (i = 0; i < VALUES_COUNT; i++) values[i] = 0;
  for (i = 0; i < N_CARDS_IN_HAND; i++) values[hand[i].value]++;
  return values;
}


struct rank check_n_of_a_kind(int* values, enum rank_type type, int n,
			      enum value_type ignore) {
  struct rank rank = init_rank();
  int i;
  for (i = VALUES_COUNT - 1; i >= 0; i--) {
    if (values[i] >= n && i != ignore) {
      rank.type = type;
      rank.value1 = i;
      break;
    }
  }
  return rank;
}


struct rank check_straight_from(int* values, enum value_type start) {
  struct rank rank = init_rank();
  int i;
  for (i = 1; i < N_CARDS_IN_HAND; i++)
    if (values[start + i] != 1) return rank;
  rank.type = STRAIGHT;
  rank.value1 = start;
  return rank;
}


enum value_type create_value(char c) {
  enum value_type value;
  if (c == TEN_CHAR) value = TEN;
  else if (c == JACK_CHAR) value = JACK;
  else if (c == QUEEN_CHAR) value = QUEEN;
  else if (c == KING_CHAR) value = KING;
  else if (c == ACE_CHAR) value = ACE;
  else value = c - '0' - DELTA_VALUES;
  return value;
}


struct card* create_hand(char* str) {
  struct card* hand = malloc(N_CARDS_IN_HAND * sizeof(struct card));
  int i = 0;
  char* card = strtok(str, SPACE);
  while (card != NULL) {
    hand[i].value = create_value(card[0]);
    hand[i].suite = card[1];
    card = strtok(NULL, SPACE);
    i++;
  }
  return hand;
}


struct rank check_high_card(struct card* hand, enum value_type exception) {
  enum value_type max_value = 0;
  int i;
  for (i = 0; i < N_CARDS_IN_HAND; i++)
    if (hand[i].value > max_value && hand[i].value != exception) max_value = hand[i].value;
  struct rank rank;
  rank.type = HIGH_CARD;
  rank.value1 = max_value;
  rank.value2 = 0;
  return rank;
}


struct rank check_one_pair(int* values) {
  return check_n_of_a_kind(values, ONE_PAIR, TWO_CARDS, EMPTY);
}


struct rank check_two_pairs(int* values) {
  struct rank rank = init_rank();
  struct rank first_pair = check_one_pair(values);
  if (first_pair.type == NONE) return rank;
  values[first_pair.value1] -= TWO_CARDS;
  struct rank second_pair = check_one_pair(values);
  values[first_pair.value1] += TWO_CARDS;
  if (second_pair.type == NONE) return rank;
  rank.type = TWO_PAIRS;
  rank.value1 = first_pair.value1;
  rank.value2 = second_pair.value1;
  return rank;
}


struct rank check_three_of_a_kind(int* values) {
  return check_n_of_a_kind(values, THREE_OF_A_KIND, THREE_CARDS, EMPTY);
}


struct rank check_straight(int* values) {
  enum value_type i;
  for (i = 0; i < VALUES_COUNT - N_CARDS_IN_HAND - 1; i++) {
    if (values[i] > 1) break;
    else if (values[i] == 1) return check_straight_from(values, i);
  }
  return init_rank();
}


struct rank check_flush(struct card* hand) {
  int i;
  struct rank rank = init_rank();
  for (i = 1; i < N_CARDS_IN_HAND; i++) {
    if (hand[i].suite != hand[0].suite)
      return rank;
  }
  rank.type = FLUSH;
  return rank;
}


struct rank check_full_house(int* values) {
  struct rank rank = init_rank();
  struct rank three_of_a_kind = check_three_of_a_kind(values);
  if (three_of_a_kind.type == NONE) return rank;
  struct rank one_pair = check_n_of_a_kind(values, ONE_PAIR, TWO_CARDS,
					   three_of_a_kind.value1);
  if (one_pair.type == NONE) return rank;
  rank.type = FULL_HOUSE;
  rank.value1 = three_of_a_kind.value1;
  rank.value2 = one_pair.value1;
  return rank;
}


struct rank check_four_of_a_kind(int* values) {
  return check_n_of_a_kind(values, FOUR_OF_A_KIND, FOUR_CARDS, EMPTY);
}


struct rank check_straight_flush(struct card* hand, int* values) {
  struct rank rank = init_rank();
  if (check_flush(hand).type == NONE) return rank;
  struct rank straight = check_straight(values);
  if (straight.type == NONE) return rank;
  rank.type = STRAIGHT_FLUSH;
  rank.value1 = straight.value1;
  return rank;
}


struct rank check_royal_flush(struct card* hand, int* values) {
  struct rank rank = init_rank();
  struct rank straight = check_straight_from(values, TEN);
  if (straight.type == NONE) return rank;
  struct rank flush = check_flush(hand);
  if (flush.type == NONE) return rank;
  rank.type = ROYAL_FLUSH;
  return rank;
}


struct rank find_max_rank(struct card* hand, int* values, struct rank ignore) {
  struct rank rank;
  rank.type = NONE;
  if (ignore.type > ROYAL_FLUSH) {
    rank = check_royal_flush(hand, values);
    if (rank.type != NONE) return rank;
  }
  if (ignore.type > STRAIGHT_FLUSH) {
    rank = check_straight_flush(hand, values);
    if (rank.type != NONE) return rank;
  }
  if (ignore.type > FOUR_OF_A_KIND) {
    rank = check_four_of_a_kind(values);
    if (rank.type != NONE) return rank;
  }
  if (ignore.type > FULL_HOUSE) {
    rank = check_full_house(values);
    if (rank.type != NONE) return rank;
  }
  if (ignore.type > FLUSH) {
    rank = check_flush(hand);
    if (rank.type != NONE) return rank;
  }
  if (ignore.type > STRAIGHT) {
    rank = check_straight(values);
    if (rank.type != NONE) return rank;
  }
  if (ignore.type > THREE_OF_A_KIND) {
    rank = check_three_of_a_kind(values);
    if (rank.type != NONE) return rank;
  }
  if (ignore.type > TWO_PAIRS) {
    rank = check_two_pairs(values);
    if (rank.type != NONE) return rank;
  }
  if (ignore.type > ONE_PAIR) {
    rank = check_one_pair(values);
    if (rank.type != NONE) return rank;
  }
  if (ignore.type > HIGH_CARD) rank = check_high_card(hand, EMPTY);
  else rank = check_high_card(hand, ignore.value1);
  return rank;
}


int compare_ranks(struct rank rank1, struct rank rank2) {
  if (rank1.type != rank2.type) return rank1.type - rank2.type;
  if (rank1.value1 != rank2.value1) return rank1.value1 - rank2.value1;
  return rank1.value2 - rank2.value2;
}


int compare(struct card* hand1, struct card* hand2) {
  int* values1 = count_values(hand1);
  int* values2 = count_values(hand2);
  struct rank rank1;
  rank1.type = NONE;
  struct rank rank2;
  rank2.type = NONE;
  int comparison;
  do {
  rank1 = find_max_rank(hand1, values1, rank1);
  rank2 = find_max_rank(hand2, values2, rank2);
  } while ((comparison = compare_ranks(rank1, rank2)) == 0);
  free(values1);
  free(values2);
  return comparison;
}


int main(int argc, char* argv[]) {
  FILE* file = fopen(FILENAME, READ);
  char line[LINE_LENGTH];
  int counter = 1;
  while(1 == 1) {
    fgets(line, LINE_LENGTH - 1, file);
    if (feof(file)) break;
    fseek(file, TWO_CHARS, SEEK_CUR);
    char p1[ONE_PLAYER_LINE_LENGTH + 1];
    strncpy(p1, line, ONE_PLAYER_LINE_LENGTH);
    p1[ONE_PLAYER_LINE_LENGTH] = 0;
    char p2[ONE_PLAYER_LINE_LENGTH + 1];
    strncpy(p2, line + ONE_PLAYER_LINE_LENGTH + 1, ONE_PLAYER_LINE_LENGTH);
    p2[ONE_PLAYER_LINE_LENGTH] = 0;
    struct card* player1 = create_hand(p1);
    struct card* player2 = create_hand(p2);
    if (compare(player1, player2) > 0) counter++;
    free(player1);
    free(player2);
  }
  fclose(file);
  printf("%d\n", counter);
  return 0;
}

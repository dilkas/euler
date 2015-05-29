#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N_PRIMES 5
#define MIN_PRIME 2
#define MAX_PRIME 10000

int recurse(int n, int sum, int best_sum, int start_index, int limit,
            int set[], int primes[], int **pair) {
  if (n == N_PRIMES - 1) {
    for (int i = start_index; i < limit; i++) {
      if (set[i]) return sum + primes[i];
    }
  }
  for (int i = start_index; (best_sum == -1 ||
                             sum + (N_PRIMES - n) * primes[i] < best_sum) &&
         i < limit; i++) {
    if (!set[i]) continue;
    int new_set[limit];
    int empty = 1;
    for (int j = 0; j < i; j++) {
      new_set[j] = set[j] && pair[j][i];
      if (new_set[j]) empty = 0;
    }
    for (int j = i + 1; j < limit; j++) {
      new_set[j] = set[j] && pair[i][j];
      if (new_set[j]) empty = 0;
    }
    if (empty) continue;
    int result = recurse(n + 1, sum + primes[i], best_sum, i + 1, limit,
                         new_set, primes, pair);
    if (result != -1 && (result < best_sum || best_sum == -1))
      best_sum = result;
  }
  return best_sum;
}

int works(int a, int b, int isprime[]) {
  int pow = 10;
  while (b >= pow) pow *= 10;
  int n = a * pow + b;
  if (n <= MAX_PRIME) return isprime[n];
  for (int p = MIN_PRIME; p <= sqrt(n); p++) {
    if (n % p == 0) return 0;
  }
  return 1;
}

int main() {
  /* Sieve of Eratosthenes */
  int isprime[MAX_PRIME + 1];
  for (int i = 0; i <= MAX_PRIME; i++) isprime[i] = 1;
  for (int i = MIN_PRIME; i <= sqrt(MAX_PRIME); i++) {
    if (!isprime[i]) continue;
    for (int j = i * i; j <= MAX_PRIME; j += i) isprime[j] = 0;
  }

  int primes[MAX_PRIME];
  int primes_limit = 0;
  for (int i = MIN_PRIME; i <= MAX_PRIME; i++) {
    if (isprime[i]) primes[primes_limit++] = i;
  }

  int **pair = (int **) malloc(primes_limit * sizeof(int *));
  for (int i = 0; i < primes_limit; i++)
    pair[i] = (int *) malloc(primes_limit * sizeof(int));
  for (int i = 0; i < primes_limit; i++) {
    for (int j = i + 1; j < primes_limit; j++) {
      pair[i][j] = works(primes[i], primes[j], isprime) &&
        works(primes[j], primes[i], isprime);
    }
  }

  int starting_set[primes_limit];
  for (int i = 0; i < primes_limit; i++) starting_set[i] = 1;

  printf("%d\n", recurse(0, 0, -1, 0, primes_limit, starting_set, primes,
                         pair));

  for (int i = 0; i < primes_limit; i++) free(pair[i]);
  free(pair);
  return 0;
}

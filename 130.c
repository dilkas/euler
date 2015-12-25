#include <math.h>
#include <stdio.h>

#define INITIAL_SUM 1985
#define INITIAL_N 705
#define HOW_MANY 20

int min_number(int number, int n, int *k) {
  while (number < n) {
    number = number * 10 + 1;
    (*k)++;
  }
  return number;
}

int A(int n) {
  int k, number;
  for (k = 0, number = min_number(0, n, &k); number % n != 0;
       number = min_number(number % n, n, &k)) {}
  return k;
}

int prime(int n) {
  for (int k = 2; k <= floor(sqrt(n)); k++) {
    if (n % k == 0) return 0;
  }
  return 1;
}

int main() {
  int sum = INITIAL_SUM;
  for (int n = INITIAL_N, counter = 0; counter < HOW_MANY; n += 2) {
    if (n % 5 != 0 && !prime(n) && (n - 1) % A(n) == 0) {
      sum += n;
      counter++;
    }
  }
  printf("%d\n", sum);
  return 0;
}

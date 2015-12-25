#include <stdio.h>

#define EXCEEDS 1000000

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

int main() {
  int n;
  for (n = EXCEEDS + 1; n % 5 == 0 || A(n) <= EXCEEDS; n += 2) {}
  printf("%d\n", n);
  return 0;
}

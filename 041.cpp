#include <iostream>
#include <algorithm>
#include <cmath>
#define DIGITS 7
using namespace std;
int toInt(int n[]) {
  int number = 0;
  for (int i = 0; i < DIGITS; i++) number += n[DIGITS - i - 1] * pow(10, i);
  return number;
}
bool isPrime(int n) {
  float sq = sqrt((float) n);
  for (int i = 2; i < sq; i++) if (n % i == 0) return false;
  return true;
}
int main() {
  int number[DIGITS];
  for (int i = DIGITS; i > 0; i--) number[DIGITS - i] = i;
  do {
    int n = toInt(number);
    if (isPrime(n)) {
      cout << n << endl;
      return 0;
    }
  } while (prev_permutation(number, number + DIGITS));
  return 0;
}

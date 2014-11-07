#include <iostream>
#include <cmath>
#define START_N 3
#define N_ITERATION 2
#define NUMBERS_TO_CHECK 3
#define LIMIT 0.1
#define FIRST_PRIME 2
using namespace std;
bool prime(int n) {
  int limit = sqrt(n);
  for (int i = FIRST_PRIME; i <= limit; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
int main() {
  int a = 1;
  int primeCount = 0;
  int nCount = 1;
  for (int n = START_N; ; n += N_ITERATION) {
    for (int i = 0; i < NUMBERS_TO_CHECK; i++) {
      a += n - 1;
      nCount++;
      if (prime(a)) primeCount++;
    }
    a += n - 1;
    nCount++;
    if ((float) primeCount / nCount < LIMIT) {
      cout << n << endl;
      return 0;
    }
  }
  return 0;
}

#include <iostream>
#include <cmath>
#define Hexagonal(n) ((n) * (2 * (n) - 1))
using namespace std;
bool isWhole(long double n) {
  return n - (long long) n == 0;
}
bool isPentagonal(long long n) {
  long double d = sqrt(24 * n + 1);
  return isWhole(d) && ((long long) d + 1) % 6 == 0;
}
int main() {
  for (long long i = 144;; i++) {
    long long n = Hexagonal(i);
    if (isPentagonal(n)) {
      cout << n << endl;
      return 0;
    }
  }
  return 0;
}

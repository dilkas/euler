#include <iostream>
#include <math.h>
using namespace std;
int prime(long long x) {
  for (long long i = 2; i <= sqrt(x); i++) {
    if (x % i == 0) {
      return 0;
    }
  }
  return 1;
}
int main() {
  long long a = 0;
  long long n = 600851475143;
  for (long long i = 2; i < sqrt(n); i++) {
    if (prime(i) == 1 && n % i == 0) {
      a = i;
    }
  }
  cout << a << endl;
}

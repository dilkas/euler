#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
int prime(int x) {
  for (int i = 2; i <= sqrt(x); i++) {
    if (x % i == 0) {
      return 0;
    }
  }
  return 1;
}
int main() {
  unsigned long long n = 0;
  for (int i = 2; i < 2000000; i++) {
    if (prime(i) == 1) {
      n += i;
    }
  }
  cout << n << endl;
}

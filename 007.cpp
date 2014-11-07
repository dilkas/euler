#include <iostream>
#include <math.h>
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
  int n = 0;
  for (int i = 2; i > 0; i++) {
    if (prime(i) == 1) {
      n++;
      if (n == 10001) {
	cout << i << endl;
	break;
      }
    }
  }
}

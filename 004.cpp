#include <iostream>
using namespace std;
int reverse(int x) {
  int r = 0;
  while (x > 0) {
    r *= 10;
    r += (x % 10);
    x /= 10;
  }
  return r;
}
int main() {
  int n = 0;
  int a = 0;
  for (int i = 999; i > 99; i--) {
    for (int j = 999; j > 99; j--) {
      n = i * j;
      if (n == reverse(n) && n > a) {
	a = n;
      }
    }
  }
  cout << a << endl;
}

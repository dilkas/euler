#include <iostream>
#include <math.h>
using namespace std;
int main() {
  int a[1000];
  int b;
  int c;
  int d = 0;
  int s = 0;
  for (int i = 0; i < 1000; i++) {
    a[i] = 0;
  }
  a[999] = 2;
  for (int i = 1; i < 1000; i++) {
    for (int j = 999; j >= 0; j--) {
      b = a[j] * 2 + d;
      if (b > 9) {
        d = floor(b / 10);
        b -= 10 * d;
      } else {
	d = 0;
      }
      a[j] = b;
    }
  }
  for (int i = 0; i < 1000; i++) {
    s += a[i];
  }
  cout << s << endl;
}

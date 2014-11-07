#include <iostream>
using namespace std;
int d(int x) {
  int s = 0;
  for (int i = 1; i < x; i++) {
    if (x % i == 0) {
      s += i;
    }
  }
  return s;
}
int main() {
  int a, b, k = 0, s = 0;
  for (int i = 2; i < 10000; i++) {
    a = d(i);
    b = d(a);
    if (b == i && i != a) {
      if (k == 0) {
	s += a + b;
	k = 1;
      } else if (k == 1) {
	k = 0;
      }
    }
  }
  cout << s << endl;
}

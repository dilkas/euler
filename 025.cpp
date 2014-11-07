#include <iostream>
#include <math.h>
using namespace std;
int main() {
  int k = 1000;
  int a[k];
  int b[k];
  int n[k];
  int t = 0;
  int s = 2;
  for (int i = 0; i < k; i++) {
    a[i] = 0;
    b[i] = 0;
    n[i] = 0;
  }
  a[k - 1] = 1;
  b[k - 1] = 1;
  while (n[0] == 0) {
    for (int i = k - 1; i >= 0; i--) {
      n[i] = a[i] + b[i] + t;
      if (n[i] > 9) {
	t = floor(n[i]/10);
	n[i] -= t * 10;
      } else {
	t = 0;
      }
      a[i] = b[i];
      b[i] = n[i];
    }
    s++;
  }
  cout << s << endl;
}

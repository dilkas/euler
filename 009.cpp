#include <iostream>
#include <math.h>
using namespace std;
int main() {
  float c;
  float k, l;
  for (float a = 1; a < 1000; a++) {
    for (float b = 1; b < 1000; b++) {
      k = pow(a, 2);
      l = pow(b, 2);
      c = sqrt(k + l);
      if (c == ceil(c) && a + b + c == 1000) {
	int x = a * b * c;
	cout << x << endl;
	return 0;
      }
    }
  }
}

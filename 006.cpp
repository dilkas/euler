#include <iostream>
#include <math.h>
using namespace std;
int main() {
  int a = 0;
  int b = 0;
  for (int i = 1; i <= 100; i++) {
    a += pow(i, 2);
    b += i;
  }
  b = pow(b, 2);
  int c = b - a;
  cout << c << endl;
}

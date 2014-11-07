#include <iostream>
using namespace std;
int main() {
  int a = 1;
  int b = 2;
  int s = 2;
  for (int n = 0; n < 4000000;) {
    n = a + b;
    a = b;
    b = n;
    if (n % 2 == 0) {
      s += n;
    }
  }
  cout << s << endl;
  return 0;
}

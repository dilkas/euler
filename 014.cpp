#include <iostream>
using namespace std;
int main() {
  unsigned long long a = 0;
  unsigned long long b;
  for (unsigned long long i = 1; i < 1000000; i++) {
    unsigned long long j = i;
    unsigned long long k = 1;
    while (j > 1) {
      if (j % 2 == 0) {
	j /= 2;
      } else {
	j *= 3;
	j++;
      }
      k++;
    }
    if (k > a) {
      a = k;
      b = i;
    }
  }
  cout << b << endl;
}

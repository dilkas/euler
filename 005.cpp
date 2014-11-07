#include <iostream>
using namespace std;
int main() {
  for (int i = 20; i > 0; i++) {
    for (int j = 1; j <= 20; j++) {
      if (i % j != 0) {
	break;
      }
      if (j == 20) {
	cout << i << endl;
	return 0;
      }
    }
  }
}

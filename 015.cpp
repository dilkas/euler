#include <iostream>
using namespace std;
int main() {
  unsigned long long x = 21;
  unsigned long long y = 21;
  unsigned long long g[x][y];
  for (unsigned long long i = 0; i < x; i++) {
    for (unsigned long long j = 0; j < y; j++) {
      if (i == 0 && j == 0) {
	g[i][j] = 1;
      } else if (i == 0) {
	g[i][j] = g[i][j - 1];
      } else if (j == 0) {
	g[i][j] = g[i - 1][j];
      } else {
	g[i][j] = g[i][j - 1] + g[i - 1][j];
      }
    }
  }
  cout << g[x - 1][y - 1] << endl;
}

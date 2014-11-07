#include <iostream>
#include <math.h>
#define MAX_P 1000
#define MIN_P 3
using namespace std;
int solutions(int p) {
  int limit = p / 2 + 1;
  int solutions = 0;
  for (int a = 1; a < limit; a++) {
    for (int b = 1; b < limit; b++) {
      if (2 * (a + b) >= p && pow(a, 2) + pow(b, 2) == pow(p - a - b, 2))
	solutions++;
    }
  }
  return solutions;
}
int main() {
  int maxSolutions = 0;
  int maxP = 0;
  for (int p = MIN_P; p <= MAX_P; p++) {
    int currentSolutions = solutions(p);
    if (currentSolutions > maxSolutions) {
      maxP = p;
      maxSolutions = currentSolutions;
    }
  }
  cout << maxP << endl;
  return 0;
}

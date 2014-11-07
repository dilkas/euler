#include <iostream>
#include <cmath>
#define TARGET 100
using namespace std;


int P(int n, int db[]) {
  if (n < 0) return 0;
  if (n == 0) return 1;
  if (db[n - 1] != 0) return db[n - 1];
  int sum = 0;
  for (int k = 1; k <= n; k++) {
    sum += pow(-1, k + 1) * (P(n - (k * (3 * k - 1)) / 2, db) +
			     P(n - (k * (3 * k + 1)) / 2, db));
  }
  db[n - 1] = sum;
  return sum;
}


int main() {
  int db[TARGET];
  for (int i = 0; i < TARGET; i++) db[i] = 0;
  cout << P(TARGET, db) - 1 << endl;
  return 0;
}

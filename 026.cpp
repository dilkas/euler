#include <iostream>
#include <vector>
#define MIN 2
#define MAX 1000
using namespace std;
short findN(vector<short> v, short n) {
  short size = v.size();
  for (short i = 0; i < size; i++) if (v[i] == n) return i;
  return -1;
}
short optimize(short n, short d) {
  if (n != 0) while (n < d) n *= 10;
  return n;
}
short cLength(short d) {
  vector<short> remainders;
  short firstN = optimize(1, d);
  short n = firstN % d;
  short count = 0;
  while (n != 0) {
    short c = findN(remainders, n);
    if (c > -1) return remainders.size() - c;
    remainders.push_back(n);
    n = optimize(n % d, d);
    count++;
  }
  return 0;
}
int main() {
  short maxLength = 0;
  short d;
  short maxD;
  for (d = MIN; d < MAX; d++) {
    short thisLength = cLength(d);
    if (thisLength > maxLength) {
      maxLength = thisLength;
      maxD = d;
    }
  }
  cout << maxD << endl;
  return 0;
}

#include <iostream>
#include <cmath>
using namespace std;
bool isPrime(int n) {
  float root = sqrt(n);
  for (int i = 2; i < root + 1; i++) if (n % i == 0) return false;
  return true;
}
bool asTwiceSquare(int n) {
  if (n % 2 != 0) return false;
  int n2 = n / 2;
  float root = sqrt(n2);
  if ((int) root == root) return true;
  return false;
}
bool canBeWritten(int n) {
  for (int i = 2; i <= n; i++)
    if (isPrime(i) && asTwiceSquare(n - i)) return true;
  return false;
}
int main() {
  for (int i = 1; ; i += 2) {
    if (!isPrime(i) && !canBeWritten(i)) {
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}

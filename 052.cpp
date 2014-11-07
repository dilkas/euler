#include <iostream>
#include <sstream>
#define START_COEF 2
#define END_COEF 6
using namespace std;
string i2s(int i) {
  stringstream ss;
  ss << i;
  return ss.str();
}
bool containsSameDigits(int a, int b) {
  string x = i2s(a);
  string y = i2s(b);
  unsigned int length = x.length();
  if (length != y.length()) return false;
  for (unsigned int i = 0; i < length; i++) {
    unsigned int c = y.find(x[i]);
    if (c == string::npos) return false;
    y.erase(c, 1);
  }
  return true;
}
bool isGoodX(int x) {
  for (int i = START_COEF; i <= END_COEF; i++)
    if (!containsSameDigits(x, i * x)) return false;
  return true;
}
int main() {
  for (int x = 1; ; x++) {
    if (isGoodX(x)) {
      cout << x << endl;
      return 0;
    }
  }
  return 0;
}

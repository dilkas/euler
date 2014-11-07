#include <iostream>
#include <sstream>
#define START 10
#define END 99
#define HOW_MANY_DIGITS 2
using namespace std;
string i2s(int i) {
  stringstream ss;
  ss << i;
  return ss.str();
}
int s2i(string s) {
  stringstream ss(s);
  int i;
  ss >> i;
  return i;
}
void convert(int &a, int &b) {
  string x = i2s(a);
  string y = i2s(b);
  for (int i = 0; i < HOW_MANY_DIGITS; i++) {
    for (int j = 0; j < HOW_MANY_DIGITS; j++) {
      if (x[i] == y[j] && x[i] != '0') {
	x.erase(i, 1);
	y.erase(j, 1);
	a = s2i(x);
	b = s2i(y);
	return;
      }
    }
  }
}
int gcd(int a, int b) {
  while (a != b) {
    if (a > b) a -= b;
    else if (b > a) b -= a;
  }
  return a;
}
int main() {
  int productNumerators = 1;
  int productDenumerators = 1;
  for (int d = START; d <= END; d++) {
    for (int n = START; n < d; n++) {
      int d2 = d;
      int n2 = n;
      convert(d2, n2);
      if ((float) n / d == (float) n2 / d2 && n != n2) {
	productNumerators *= n;
	productDenumerators *= d;
      }
    }
  }
  cout << productDenumerators / gcd(productNumerators, productDenumerators) << endl;
}

#include <iostream>
#include <sstream>
#include <set>
#define MAX 9876
#define N_PANDIGITAL 9
using namespace std;
string i2s(int a, int b, int c) {
  stringstream ss;
  ss << a << b << c;
  return ss.str();
}
bool allNull(char digits[]) {
  for (int i = 0; i < N_PANDIGITAL; i++) if (digits[i] != '0') return false;
  return true;
}
int main() {
  set<int> pandigital;
  for (int i = 1; i < MAX; i++) {
    for (int j = 1; j < i; j++) {
      int product = i * j;
      string s = i2s(i, j, product);
      int length = s.length();
      if (length > 9) break;
      if (length == 9) {
	char digits[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
	for (int a = 0; a < N_PANDIGITAL; a++) digits[s[a] - '1'] = '0';
	if (allNull(digits)) pandigital.insert(product);
      }
    }
  }
  int sum = 0;
  for (set<int>::iterator it = pandigital.begin(); it != pandigital.end();
       it++) {
    sum += *it;
  }
  cout << sum << endl;
}

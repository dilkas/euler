#include <iostream>
#include <algorithm>
#include <sstream>
#define MAX_I 10000
#define MIN_N 2
#define LENGTH 9
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
int concatinate(int i, int n) {
  string s;
  for (int a = 1; a <= n; a++) s += i2s(a * i);
  return s2i(s);
}
bool isPandigital(int n) {
  string s = i2s(n);
  if (s.length() != 9) return false;
  char digits[LENGTH];
  for (int i = 0; i < LENGTH; i++) digits[i] = '0' + i + 1;
  for (int i = 0; i < LENGTH; i++) digits[s[i] - '0' - 1] = '0';
  for (int i = 0; i < LENGTH; i++) if (digits[i] != '0') return false;
  return true;
}
int main() {
  int max = 0;
  for (int i = 1; i < MAX_I; i++) {
    for (int n = 2; n < 9; n++) {
      int result = concatinate(i, n);
      if (result > max && isPandigital(result)) max = result;
    }
  }
  cout << max << endl;
  return 0;
}

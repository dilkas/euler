#include <iostream>
#include <sstream>
#define MAX 1000000
using namespace std;
string i2s(int i) {
  stringstream ss;
  ss << i;
  return ss.str();
}
int main() {
  string fraction = "";
  for (int i = 1; i < MAX; i++) fraction += i2s(i);
  int product = 1;
  for (int i = 1; i <= MAX; i *= 10) product *= fraction[i - 1] - '0';
  cout << product << endl;
}

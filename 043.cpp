#include <iostream>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <string>
#define MAX_DIGIT 9
using namespace std;
string i2s(unsigned long long i) {
  stringstream ss;
  ss << i;
  return ss.str();
}
unsigned long long s2i(string s) {
  stringstream ss(s);
  unsigned long long i;
  ss >> i;
  return i;
}
unsigned long long toInt(unsigned long long number[]) {
  unsigned long long n = 0;
  for (unsigned long long i = 0; i <= MAX_DIGIT; i++)
    n += number[MAX_DIGIT - i] * pow(10, i);
  return n;
}
bool isOk(string s) {
  unsigned long long divisors[] = {2, 3, 5, 7, 11, 13, 17};
  for (unsigned long long i = 0; i <= MAX_DIGIT - 3; i++) {
    if (s2i(s.substr(i + 1, 3)) % divisors[i] != 0) return false;
  }
  return true;
}
int main() {
  unsigned long long number[MAX_DIGIT + 1];
  unsigned long long sum = 0;
  for (unsigned long long i = 0; i <= MAX_DIGIT; i++) number[i] = i;
  do {
    unsigned long long n = toInt(number);
    string s = i2s(n);
    if (isOk(s)) sum += n;
  } while (next_permutation(number, number + MAX_DIGIT + 1));
  cout << sum << endl;
  return 0;
}

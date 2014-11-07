#include <cmath>
#include <iostream>
#include <sstream>
#include <set>
#define MAX_A 9
#define MAX_N 21
using namespace std;
unsigned long long length(unsigned long long n) {
  stringstream ss;
  ss << n;
  string s = ss.str();
  return s.length();
}
int main() {
  set<unsigned long long> s;
  for (unsigned long long n = 1; n <= MAX_N; n++) {
    for (unsigned long long a = 1; a <= MAX_A; a++)
      if (length(pow(a, n)) == n) s.insert(pow(a, n));
  }
  cout << s.size() + 1 << endl; // programavimo kalbos apvalinimo klaida
  return 0;
}

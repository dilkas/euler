#include <iostream>
#include <fstream>
#include <math.h>
#define FILENAME "words.txt"
using namespace std;
bool isTriangle(int a) {
  float root = sqrt(1 + 8 * a);
  if ((int) root != root) return false;
  return (int) root % 2 == 1;
}
int main() {
  fstream f;
  f.open(FILENAME);
  int sum = 0;
  int count = 0;
  while (f.good()) {
    char c = f.get();
    if (c != '"' && c != ',') {
      sum += (int) c - 'A' + 1;
    } else if (c == ',') {
      if (isTriangle(sum)) count++;
      sum = 0;
    }
  }
  cout << count << endl;
  f.close();
  return 0;
}

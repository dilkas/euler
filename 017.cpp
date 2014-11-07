#include <iostream>
#include <sstream>
#include <map>
#include <math.h>
#include <string.h>
using namespace std;
map <int, string> c;
map <int, string> e;
map <int, string> f;
string ten(int x) {
  int z;
  string y;
  if (x == 10) {
    y = "ten";
    x = 0;
  } else if (x < 20 && x > 10) {
    y = f.find(x)->second;
    x = 0;
  } else if (x >= 20) {
    z = floor(x / 10);
    x -= z * 10;
    y = e.find(z)->second;
    if (x > 0) {
      y += c.find(x)->second;
    }
  } else if (x < 10) {
    y = c.find(x)->second;
  }
  return y;
}
int main() {
  int a[1000];
  int d;
  string b[1000];
  int g = 0;
  c[1] = "one";
  c[2] = "two";
  c[3] = "three";
  c[4] = "four";
  c[5] = "five";
  c[6] = "six";
  c[7] = "seven";
  c[8] = "eight";
  c[9] = "nine";
  e[2] = "twenty";
  e[3] = "thirty";
  e[4] = "forty";
  e[5] = "fifty";
  e[6] = "sixty";
  e[7] = "seventy";
  e[8] = "eighty";
  e[9] = "ninety";
  f[11] = "eleven";
  f[12] = "twelve";
  f[13] = "thirteen";
  f[14] = "fourteen";
  f[15] = "fifteen";
  f[16] = "sixteen";
  f[17] = "seventeen";
  f[18] = "eighteen";
  f[19] = "nineteen";
  for (int i = 0; i < 1000; i++) {
    a[i] = i + 1;
  }
  for (int i = 0; i < 1000; i++) {
     if (a[i] == 1000) {
      b[i] = "onethousand";
      a[i] = 0;
     } else if (a[i] >= 100) {
       d = floor(a[i] / 100);
       b[i] = c.find(d)->second + "hundred";
       a[i] -= d * 100;
       if (a[i] > 0) {
	 b[i] += "and";
	 b[i] += ten(a[i]);
	 a[i] = 0;
       }
     } else {
       b[i] = ten(a[i]);
       a[i] = 0;
     }
  }
  for (int i = 0; i < 1000; i++) {
    g += b[i].length();
  }
  cout << g << endl;
}

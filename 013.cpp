#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
int main() {
  ifstream f ("test13.txt");
  char t[100][50];
  int n[100][50];
  int ans[52];
  string l;
  string a;
  int ax = 0;
  int ay = 0;
  int az = 0;
  for (int i = 0; i < 100; i++) {
    getline(f, l);
    strcpy(t[i], l.c_str());
  }
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 50; j++) {
      n[i][j] = t[i][j] - '0';
    }
  }
  for (int i = 49; i >= 0; i--) {
    int s = 0;
    for (int j = 0; j < 100; j++) {
      s += n[j][i];
    }
    int x = floor(s / 100);
    int b = s - x * 100;
    int y = floor(b / 10);
    int z = s - x * 100 - y * 10;
    az = z + ay;
    ay = y + ax;
    ax = x;
    if (az > 9) {
      int k = floor(az / 10);
      ay += k;
      az -= k * 10;
    }
    if (ay > 9) {
      int l = floor(ay / 10);
      ax += l;
      ay -= l * 10;
    }
    ans[i + 2] = az;
  }
  ans[1] = ay;
  ans[0] = ax;
  for (int i = 0; i < 10; i++) {
    int temp = ans[i];
    cout << temp;
  }
  cout << endl;
}

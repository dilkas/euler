#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <stdlib.h>
using namespace std;
int main() {
  ifstream f ("test11.txt");
  int t[20][20];
  string l;
  string a;
  int x = 1;
  int y = 0;
  for (int i = 0; i < 20; i++) {
    getline (f, l);
    istringstream s(l);
    for (int j = 0; j < 20; j++) {
      getline (s, a, ' ');
      t[i][j] = atoi(a.c_str());
    }
  }
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 17; j++) {
      x = 1;
      for (int k = 0; k < 4; k++) {
	x *= t[i][j+k];
	if (x > y) {
	  y = x;
	}
      }
    }
  }
  for (int i = 0; i < 17; i++) {
    for (int j = 0; j < 20; j++) {
      x = 1;
      for (int k = 0; k < 4; k++) {
	x *= t[i+k][j];
	if (x > y) {
	  y = x;
	}
      }
    }
  }
  for (int i = 0; i < 17; i++) {
    for (int j = 0; j < 17; j++) {
      x = 1;
      for (int k = 0; k < 4; k++) {
	x *= t[i+k][j+k];
	if (x > y) {
	  y = x;
	}
      }
    }
  }
  for (int i = 0; i < 17; i++) {
    for (int j = 3; j < 20; j++) {
      x = 1;
      for (int k = 0; k < 4; k++) {
	x *= t[i+k][j-k];
	if (x > y) {
	  y = x;
	}
      }
    }
  }
  cout << y << endl;
}

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#define FILENAME "triangle.txt"
#define SIZE 100
using namespace std;
int main() {
  ifstream file;
  file.open(FILENAME);
  string line, number;
  short triangle[SIZE][SIZE], i = 0;
  while (file.good()) {
    getline(file, line);
    if (line == "") break;
    stringstream ss(line);
    short j = 0;
    while (!ss.eof()) {
      getline(ss, number, ' ');
      triangle[i][j++] = atoi(number.c_str());
    }
    i++;
  }
  file.close();
  for (short i = SIZE - 2; i >= 0; i--) {
    for (short j = 0; j <= i; j++)
      triangle[i][j] += (triangle[i + 1][j] > triangle[i + 1][j + 1]) ?
	triangle[i + 1][j] : triangle[i + 1][j + 1];
  }
  cout << triangle[0][0] << endl;
  return 0;
}

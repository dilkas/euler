#include <iostream>
#include <fstream>
#include <sstream>
#define FILENAME "matrix.txt"
#define SIZE 79
#define DELIMETER ','
#define START_S 2 * SIZE - 1
using namespace std;


int main() {
  int matrix[SIZE + 1][SIZE + 1];
  ifstream file;
  file.open(FILENAME);
  for (int i = 0; i <= SIZE; i++) {
    string line;
    getline(file, line);
    stringstream lineSs(line);
    for (int j = 0; j <= SIZE; j++) {
      string numberS;
      getline(lineSs, numberS, DELIMETER);
      stringstream numberSs(numberS);
      int number;
      numberSs >> number;
      matrix[i][j] = number;
    }
  }
  file.close();
  for (int s = START_S; s >= 0; s--) {
    int x;
    int y;
    if (s < SIZE) {
      x = s;
      y = 0;
    } else {
      x = SIZE;
      y = s - SIZE;
    }
    while (x >= 0 && y <= SIZE) {
      if (x == SIZE) matrix[x][y] += matrix[x][y + 1];
      else if (y == SIZE) matrix[x][y] += matrix[x + 1][y];
      else matrix[x][y] += min(matrix[x + 1][y], matrix[x][y + 1]);
      x--;
      y++;
    }
  }
  cout << matrix[0][0] << endl;
  return 0;
}

#include <iostream>
#define SIZE 1001
#define CENTER SIZE / 2
using namespace std;
void drawSquare(int spiral[SIZE][SIZE], int &size, int &nToWrite) {
  int constC = CENTER + size;
  for (int i = -size + 1; i <= size; i++)
    spiral[CENTER + i][constC] = nToWrite++;
  for (int i = size - 1; i >= -size; i--)
    spiral[constC][CENTER + i] = nToWrite++;
  constC = CENTER - size;
  for (int i = size - 1; i >= -size; i--)
    spiral[CENTER + i][constC] = nToWrite++;
  for (int i = -size + 1; i <= size; i++)
    spiral[constC][CENTER + i] = nToWrite++;
}
int sumDiagonals(int spiral[SIZE][SIZE]) {
    int sum = -1;
    int j = SIZE - 1;
    for (int i = 0; i < SIZE; i++) sum += spiral[i][i] + spiral[i][j--];
    return sum;
}
int main() {
  int spiral[SIZE][SIZE];
  int n = 2;
  spiral[CENTER][CENTER] = 1;
  for (int i = 1; i < CENTER + 1; i++) drawSquare(spiral, i, n);
  cout << sumDiagonals(spiral) << endl;
  return 0;
}

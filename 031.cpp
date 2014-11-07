#include <iostream>
#define TARGET 200
#define SIZE 8
using namespace std;
int try2sum(int target, int numbers[], int startI) {
  if (target == 0) return 1;
  int waysToReach = 0;
  for (int i = startI; i < SIZE; i++)
    if (numbers[i] <= target) waysToReach += try2sum(target - numbers[i], numbers, i);
  return waysToReach;
}
int main() {
  int numbers[] = {200, 100, 50, 20, 10, 5, 2, 1};
  cout << try2sum(TARGET, numbers, 0) << endl;
}

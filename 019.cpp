#include <iostream>
using namespace std;
int mtod(int x, int y) {
  if (x == 4 || x == 6 || x == 9 || x == 11) {
    return 30;
  } else if (x == 2) {
    if (y % 4 == 0) {
      return 29;
    } else {
      return 28;
    }
  } else {
    return 31;
  }
}
int main() {
  int day = 5;
  int month = 1;
  int year = 1901;
  int temp;
  int sum = 0;
  while (year < 2001) {
    day += 7;
    temp = mtod(month, year);
    if (day > temp) {
      month++;
      if (month > 12) {
	year++;
	month = 1;
      }
      day -= temp;
    }
    if (day == 1) {
      sum++;
    }
  }
  cout << sum << endl;
}

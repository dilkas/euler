#include <iostream>
#include <vector>
#define MAX 28123
using namespace std;
int sumOfDivisors(int n) {
  int sum = 0;
  for (int i = 1; i < n; i++) if (n % i == 0) sum += i;
  return sum;
}
int main() {
  vector<int> abundantNumbers;
  for (int i = 1; i < MAX; i++)
    if (sumOfDivisors(i) > i) abundantNumbers.push_back(i);
  int result[MAX - 1];
  for (int i = 1; i < MAX; i++) result[i - 1] = i;
  for (vector<int>::iterator it = abundantNumbers.begin();
       it < abundantNumbers.end(); it++) {
    for (vector<int>::iterator it2 = abundantNumbers.begin();
	 it2 < abundantNumbers.end(); it2++) {
      int sum = *it + *it2;
      if (sum < MAX) result[sum - 1] = 0;
    }
  }
  int sum = 0;
  for (int i = 0; i < MAX - 1; i++) {
    sum += result[i];
  }
  cout << sum << endl;
}

#include <iostream>
#include <cmath>

using namespace std;
const int N = 10000000;

int main() {
  int *num_divisors = new int[N];
  for (int i = 0; i < N; i++)
    num_divisors[i] = 0;

  for (int i = 2; i < N; i++) {
    // using square roots to avoid integer overflow
    for (int j = i + i; j < N && sqrt(j) < i; j += i)
      num_divisors[j] += 2;
    if (i < sqrt(N))
      num_divisors[i * i]++;
  }

  int count = 0;
  for (int n = 3; n < N; n++) {
    if (num_divisors[n] == num_divisors[n - 1])
      count++;
  }
  cout << count << endl;
  delete[] num_divisors;
}

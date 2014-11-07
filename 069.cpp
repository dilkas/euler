/*****************************************************************************
 * Yra geresnis budas be programos.
 *****************************************************************************/
#include <iostream>
#define MAX_N 1000000
using namespace std;
void nextP(int &p, int numbers[]) {
  for (int i = p - 1; i < MAX_N - 1; i++) {
    if (numbers[i] != 0) {
      p = numbers[i];
      return;
    }
  }
}


int phi(int n, int numbers[], int phis[]) {
  int phi = 1;
  for (int i = 0; i < n; i++) {
    int d = i + 2;
    if (numbers[i] != 0 && n % d == 0) {
      long long m = d;
      while (n % m == 0) m *= d;
      m /= d;
      phi *= phis[m - 2];
      n /= m;
    }
  }
  return phi;
}


int main() {
  int numbers[MAX_N - 1];
  for (int i = 0; i < MAX_N - 1; i++) numbers[i] = i + 2;
  for (int p = 2; p * p <= MAX_N; nextP(p, numbers)) {
    for (int n = p * p; n <= MAX_N; n += p)
      numbers[n - 2] = 0;
  }

  int phis[MAX_N - 1];
  for (int i = 0; i < MAX_N - 1; i++) {
    if (numbers[i] != -1) {
      if (numbers[i] != 0) {
	phis[i] = numbers[i] - 1;
	long long n = numbers[i];
	while (1) {
	  n *= numbers[i];
	  if (n > MAX_N) break;
	  numbers[n - 2] = -1;
	  phis[n - 2] = n - n / numbers[i];
	}
      } else phis[i] = phi(i + 2, numbers, phis);
    }
  }

  float maxFraction = 0;
  int maxN = 0;
  for (int n = 2; n <= MAX_N; n++) {
    float t = (float) n / phis[n - 2];
    if (t > maxFraction) {
      maxFraction = t;
      maxN = n;
    }
  }
  cout << maxN << endl;
}

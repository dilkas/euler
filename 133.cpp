#include <iostream>
#include <cmath>
#include <vector>

#define LIMIT 100000

using namespace std;

int min_number(int number, int n, int &k) {
  while (number < n) {
    number = number * 10 + 1;
    k++;
  }
  return number;
}

int A(int n) {
  int k, number;
  for (k = 0, number = min_number(0, n, k); number % n != 0;
       number = min_number(number % n, n, k)) {}
  return k;
}

bool prime(int n, vector<int> &primes) {
  for (vector<int>::iterator it = primes.begin(); it != primes.end(); it++) {
    if (*it > sqrt(n)) break;
    if (n % *it == 0) return false;
  }
  return true;
}

int next_prime(int p, vector<int> &primes) {
  int n;
  for (n = p + 1; !prime(n, primes); n++) {}
  primes.push_back(p);
  return n;
}

bool divisor(int n) {
  while (n % 2 == 0) n /= 2;
  while (n % 5 == 0) n /= 5;
  return n == 1;
}

int main() {
  vector<int> primes;
  primes.push_back(2);
  primes.push_back(3);
  primes.push_back(5);
  int sum = 10;
  for (int p = 7; p < LIMIT; p = next_prime(p, primes)) {
    if (!divisor(A(p))) sum += p;
  }
  cout << sum << endl;
  return 0;
}

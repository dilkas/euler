// > 1 min., bet geresniu neradau
#include <iostream>
#include <vector>
#include <cmath>
#define N_CONSECUTIVE 4
#define N_DISTINCT_PRIMES 4
using namespace std;
bool isPrime(int number, vector<int> &primes) {
  for (vector<int>::iterator it = primes.begin(); it != primes.end(); it++)
    if (number % *it == 0) return false;
  return true;
}
void makeMorePrimes(vector<int> &primes, int limit) {
  for (int number = primes.back() + 1; number <= limit; number++)
    if (isPrime(number, primes)) primes.push_back(number);
}
int countDistinctPrimeFactors(int number, vector<int> &primes) {
  int count = 0;
  if (primes.back() < number) makeMorePrimes(primes, number);
  for (vector<int>::iterator it = primes.begin(); it != primes.end(); it++)
    if (number % *it == 0) count++;
  return count;
}
int main() {
  vector<int> primes;
  primes.push_back(2);
  for (int number = 1; ; number++) {
    bool flag = true;
    for (int increment = 0; increment < N_CONSECUTIVE; increment++) {
      if (countDistinctPrimeFactors(number + increment, primes) !=
	  N_DISTINCT_PRIMES) {
	flag = false;
	break;
      }
    }
    if (flag == true) {
      cout << number << endl;
      return 0;
    }
  }
  return 0;
}

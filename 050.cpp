#include <iostream>
#include <algorithm>
#include <cstdlib>
#define LIMIT 1000000
#define SIZE 78498
#define FIRST_PRIME 2
using namespace std;


void nextP(unsigned long long &p, unsigned long long array[]) {
  for (unsigned long long i = p - 1; i < LIMIT - 2; i++) {
    if (array[i] != 0) {
      p = array[i];
      return;
    }
  }
}


int compare(const void * a, const void * b) {
  return (*(unsigned long long *) a - *(unsigned long long *) b);
}


void test(unsigned long long &n, unsigned long long primes[],
	  unsigned long long &size, unsigned long long &maxTerms,
	  unsigned long long &maxPrime, unsigned long long termsCount) {
  if (n < LIMIT && termsCount > maxTerms &&
      bsearch(&n, primes, size, sizeof(unsigned long long), compare)) {
    maxTerms = termsCount;
    maxPrime = n;
  }
}


int main() {
  unsigned long long tempPrimes[LIMIT - 2];
  for (unsigned long long i = 0; i < LIMIT - 2; i++) tempPrimes[i] = i + 2;
  for (unsigned long long p = FIRST_PRIME; p * p < LIMIT - 2;
       nextP(p, tempPrimes)) {
    for (unsigned long long n = p * p; n < LIMIT; n += p)
      tempPrimes[n - 2] = 0;
  }
  unsigned long long count = 0;
  for (unsigned long long i = 0; i < LIMIT - 2; i++)
    if (tempPrimes[i] != 0) count++;
  unsigned long long *primes = new unsigned long long[SIZE];
  unsigned long long j = 0;
  for (unsigned long long i = 0; i < LIMIT - 2; i++)
    if (tempPrimes[i] != 0) primes[j++] = tempPrimes[i];
  unsigned long long *sums = new unsigned long long[SIZE];
  unsigned long long sum = 0;
  for (unsigned long long i = 0; i < count; i++) {
    sum += primes[i];
    sums[i] = sum;
  }
  unsigned long long maxTerms = 0;
  unsigned long long maxPrime = 0;
  for (long long j = count - 1; j >= 0; j--) {
    test(sums[j], primes, count, maxTerms, maxPrime, j + 1);
    for (unsigned long long i = 0; i < min(count - j, (unsigned long long) j);
	 i++) {
      unsigned long long termsCount = j - i;
      unsigned long long currentSum = sums[j] - sums[i];
      test(currentSum, primes, count, maxTerms, maxPrime, termsCount);
    }
  }
  delete(primes);
  delete(sums);
  cout << maxPrime << endl;
  cout << maxTerms << endl;
  return 0;
}

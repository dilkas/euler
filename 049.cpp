#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <set>
#define FIRST_PRIME 2
#define LIMIT_FOR_TESTING_PRIMES 100
#define FIRST_N 1000
#define MAX_N 9999
#define HOW_MANY 3
using namespace std;
string i2s(int n) {
  stringstream ss;
  ss << n;
  return ss.str();
}
string findKey(int n) {
  vector<char> tempVector;
  string str = i2s(n);
  int length = str.length();
  for (int i = 0;  i< length; i++) tempVector.push_back(str[i]);
  sort(tempVector.begin(), tempVector.end());
  string result = "";
  for (vector<char>::iterator it = tempVector.begin(); it != tempVector.end();
       it++)
    result += *it;
  return result;
}
bool isPrime(int n, vector<int> &primes) {
  for (vector<int>::iterator it = primes.begin(); it != primes.end(); it++)
    if (n % *it == 0) return false;
  return true;
}
void nextP(int numbers[], int &p) {
  for (int i = p - 1; i < LIMIT_FOR_TESTING_PRIMES - 2; i++) {
    if (numbers[i] != 0) {
      p = numbers[i];
      return;
    }
  }
}
bool findN(vector<int> &v, int n) {
  for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    if (*it == n) return true;
  return false;
}
bool isProgression(vector<int> &v) {
  set<int> deltas;
  for (vector<int>::iterator it = v.begin(); it != v.end() - 1; it++) {
    for (vector<int>::iterator it2 = it + 1; it2 != v.end(); it2++) {
      int lastN = 2 * *it2 - *it;
      if (findN(v, lastN)) {
	cout << *it << *it2 << lastN <<endl;
      }
    }
  }
  return false;
}
int main() {
  int testingPrimes[LIMIT_FOR_TESTING_PRIMES - 2];
  for (int i = 2; i < LIMIT_FOR_TESTING_PRIMES; i++)
    testingPrimes[i - 2] = i;
  for (int p = 2; p < LIMIT_FOR_TESTING_PRIMES - 3; nextP(testingPrimes, p)) {
    for (int i = 2 * p - 2; i < LIMIT_FOR_TESTING_PRIMES - 2; i += p)
      testingPrimes[i] = 0;
  }
  vector<int> testPrimes;
  for (int i = 0; i < LIMIT_FOR_TESTING_PRIMES - 2; i++)
    if (testingPrimes[i] != 0) testPrimes.push_back(testingPrimes[i]);
  vector<int> primes;
  for (int number = FIRST_N; number <= MAX_N; number++)
    if (isPrime(number, testPrimes)) primes.push_back(number);
  map<string, vector<int> > permutations;
  for (vector<int>::iterator it = primes.begin(); it != primes.end(); it++)
    permutations[findKey(*it)].push_back(*it);
  for (map<string, vector<int> >::iterator it = permutations.begin();
	 it != permutations.end(); it++) {
    if ((*it).second.size() >= HOW_MANY) {
      sort((*it).second.begin(), (*it).second.end());
      if (isProgression((*it).second)) return 0;
    }
  }
  return 0;
}

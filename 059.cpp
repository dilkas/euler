#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#define FILENAME "cipher1.txt"
#define FIRST_LETTER 'a'
#define LAST_LETTER 'z'
#define NCHARS 3
#define SEPARATOR ','
#define FIRST_KEY "aaa"
#define KEYWORD "Gospel"
using namespace std;


bool nextKey(string &key) {
  for (int i = NCHARS - 1; i >= 0; i--) {
    if (key[i] != LAST_LETTER) {
      key[i] += 1;
      for (int j = NCHARS - 1; j > i; j--) key[j] = FIRST_LETTER;
      return true;
    }
  }
  return false;
}


string decrypt(vector<int> ciphered, string key) {
  int i = 0;
  string pl = "";
  for (vector<int>::iterator it = ciphered.begin(); it != ciphered.end();
       it++) {
    pl += *it ^ key[i];
    if (++i == NCHARS) i = 0;
  }
  return pl;
}


int main() {
  ifstream file;
  file.open(FILENAME);
  string oneN;
  vector<int> ciphered;
  while (getline(file, oneN, SEPARATOR)) {
    stringstream tempSs(oneN);
    int nAsInt;
    tempSs >> nAsInt;
    ciphered.push_back(nAsInt);
  }
  file.close();
  string key = FIRST_KEY;
  do {
    string plain = decrypt(ciphered, key);
    if (plain.find(KEYWORD) != string::npos) {
      int sum = 0;
      int length = plain.length();
      for (int i = 0; i < length; i++) sum += plain[i];
      cout << sum << endl;
      return 0;
    }
   } while(nextKey(key));
  return 0;
}

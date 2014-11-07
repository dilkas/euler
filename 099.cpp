#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#define FILENAME "base_exp.txt"
#define COMMA ','
using namespace std;


int s2i(string s) {
  stringstream ss(s);
  int i;
  ss >> i;
  return i;
}


int main() {
  ifstream file;
  file.open(FILENAME);
  string line;
  int line_n = 0;
  int max_line_n = 0;
  double max_pair = 0;
  while (file.good()) {
    line_n++;
    getline(file, line);
    stringstream ss(line);
    string s_base, s_exp;
    getline(ss, s_base, COMMA);
    getline(ss, s_exp, COMMA);
    int base = s2i(s_base);
    int exp = s2i(s_exp);
    double value = exp * log((double) base);
    if (value > max_pair) {
      max_pair = value;
      max_line_n = line_n;
    }
  }
  file.close();
  cout << max_line_n << endl;
  return 0;
}

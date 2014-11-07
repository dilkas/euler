#include <iostream>
using namespace std;
void swap(string &str, int i, int j) {
  char temp = str[i];
  str[i] = str[j];
  str[j] = temp;
}
void reverse(string &str, int from) {
  int length = str.length();
  for (int i = from; i < (from + length) / 2; i++) {
    swap(str, i, length - i - 1 + from);
  }
}
void permute(string &a) {
  int length = a.length();
  for (int k = length - 2; k >= 0; k--) {
    if (a[k] < a[k + 1]) {
      for (int l = length - 1; l >= 0; l--) {
	if (a[k] < a[l]) {
	  swap(a, k, l);
	  reverse(a, k + 1);
	  return;
	}
      }
    }
  }
}
int main() {
  string permutation = "0123456789";
  for (int i = 0; i < 999999; i++) permute(permutation);
  cout << permutation << endl;
  return 0;
}

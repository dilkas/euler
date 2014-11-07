#include <iostream>
#include <fstream>
#include <set>
#define COLUMNS 2
#define NUMBERS 10
#define FILENAME "keylog.txt"
#define MAX 100
using namespace std;
int main() {
  set<int> db[NUMBERS][COLUMNS];
  ifstream file;
  string line;
  file.open(FILENAME);
  while (file.good()) {
    getline(file, line);
    if (line != "") {
      db[line[0] - '0'][1].insert(line[1] - '0');
      db[line[0] - '0'][1].insert(line[2] - '0');
      db[line[1] - '0'][0].insert(line[0] - '0');
      db[line[1] - '0'][1].insert(line[2] - '0');
      db[line[2] - '0'][0].insert(line[0] - '0');
      db[line[2] - '0'][0].insert(line[1] - '0');
    }
  }
  file.close();
  string pass;
  for (int n = 0; n < NUMBERS; n++) {
    unsigned int minBefore = MAX;
    int minIndex = NUMBERS;
    for (int i = 0; i < NUMBERS; i++) {
      if (db[i][0].size() < minBefore && db[i][0].size() + db[i][1].size() > 0) {
	minBefore = db[i][0].size();
	minIndex = i;
      }
    }
    if (minIndex == NUMBERS) break;
    pass += minIndex + '0';
    db[minIndex][0].clear();
    db[minIndex][1].clear();
  }
  cout << pass << endl;
  return 0;
}

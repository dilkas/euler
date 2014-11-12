#include <stdio.h>
#include <stdlib.h>
#define FILENAME "cipher1.txt"
#define FIRST_LETTER 'a'
#define LAST_LETTER 'z'
#define NUMBER_OF_CHARS 3
#define SEPARATOR ','
#define FIRST_KEY "aaa"

int nextKey(char* key) {
  int i;
  for (i = NUMBER_OF_CHARS - 1; i >= 0; i--) {
    if (key[i] != LAST_LETTER) {
      key[i] += 1;
      int j;
      for (j = LAST_LETTER; )
    }
  }
}

int main(int argc, char* argv[]) {

  return 0;
}

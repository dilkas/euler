#include <stdio.h>
#define LIMIT 20000
#define TARGET 1000

int main() {
  int C[LIMIT], c;
  for (int i = 0; i < LIMIT; i++) C[i] = 0;
  for (int x = 1; x <= (LIMIT - 2) / 4; x++) {
    for (int y = x; y <= (LIMIT - 2 * x) / (2 * (x + 1)); y++) {
      for (int z = y; z <= (LIMIT - 2 * x * y) / (2 * (x + y)); z++) {
        for (int n = 1; (c = 2 * (x * y + y * z + x * z)
                         + 4 * (x + y + z + n - 2) * (n - 1)) < LIMIT; n++)
          C[c]++;
      }
    }
  }
  for (int i = 0; i < LIMIT; i++) {
    if (C[i] == TARGET) {
      printf("%d\n", i);
      break;
    }
  }
  return 0;
}

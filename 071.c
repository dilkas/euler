#include <stdio.h>
#include <math.h>
#define MAX 1000000
#define A 3.0
#define B 7.0

int main(int argc, char* argv[]) {
  float r = -1;
  float s = 1;
  float q;
  for (q = 2; q <= MAX; q++) {
    float p = floor((A * q - 1) / B);
    if (r * q < p * s) {
      r = p;
      s = q;
    }
  }
  printf("%d\n", (int) r);
  return 0;
}

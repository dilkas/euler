#include <stdio.h>
#include <stdlib.h>
#define D_MAX 12000
#define INIT_D 2
#define MAX_F 0.5
#define ONE_THIRD 1 / 3


int gcd(int a, int b) {
  int t;
  while (b != 0) {
    t = b;
    b = a % b;
    a = t;
  }
  return a;
}


int main(int argc, char* argv[]) {
  int d;
  int c = 0;
  float third = (float) ONE_THIRD;
  for (d = INIT_D; d <= D_MAX; d++) {
    int n = 1;
    float fr = (float) n / d;
    while (fr < MAX_F) {
      if (fr > third && gcd(n, d) == 1) c++;
      n++;
      fr = (float) n / d;
    }
  }
  printf("%d\n", c);
  return 0;
}

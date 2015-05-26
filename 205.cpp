#include <cstdio>
#include <cassert>

#define PETER_DICE 9
#define PETER_RANGE 4
#define PETER_MAX PETER_DICE * PETER_RANGE
#define COLIN_DICE 6
#define COLIN_RANGE 6
#define COLIN_MAX COLIN_DICE * COLIN_RANGE

using namespace std;

double probability(int s, int n, int k) {
    if (k < n || k > s * n) return 0;
    if (n == 1) return 1.0 / s;
    double total = 0;
    for (int i = 1; i <= s; i++)
        total += probability(s, 1, i) * probability(s, n - 1, k - i);
    assert(total <= 1);
    assert(total >= 0);
    return total;
}

double probabilityPeter(int k) {
    return probability(PETER_RANGE, PETER_DICE, k);
}

double probabilityColin(int k) {
    return probability(COLIN_RANGE, COLIN_DICE, k);
}

int main() {
    double winProbability = 0;
    for (int kPeter = PETER_MAX; kPeter >= PETER_DICE; kPeter--) {
        double colinLess = 0;
        for (int kColin = COLIN_DICE; kColin < kPeter && kColin < COLIN_MAX;
             kColin++) {
            colinLess += probabilityColin(kColin);
        }
        winProbability += probabilityPeter(kPeter) * colinLess;
    }
    printf("%.7f\n", winProbability);
    return 0;
}

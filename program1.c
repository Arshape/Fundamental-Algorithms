#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contract.h"

int main(void) {
    char line[256];
    while (fgets(line, sizeof(line), stdin)) {
        char cmd;
        if (sscanf(line, " %c", &cmd) != 1) continue;

        if (cmd == '1') {
            int a, b;
            if (sscanf(line, "1 %d %d", &a, &b) == 2) {
                printf("gcd(%d, %d) = %d\n", a, b, gcd(a, b));
            }
        } else if (cmd == '2') {
            int k;
            if (sscanf(line, "2 %d", &k) == 1) {
                printf("pi(%d) = %f\n", k, pi(k));
            }
        }
    }
    return 0;
}

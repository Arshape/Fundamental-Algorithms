#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
#include "contract.h"

typedef int (*gcd_func)(int, int);
typedef float (*pi_func)(int);

int main(void) {
    void *lib = NULL;
    gcd_func gcd_ptr = NULL;
    pi_func pi_ptr = NULL;
    char line[256];

    while (fgets(line, sizeof(line), stdin)) {
        char cmd;
        if (sscanf(line, " %c", &cmd) != 1) continue;

        if (cmd == '0') {
            char path[200];
            if (sscanf(line, "0 %199s", path) != 1) continue;

            if (lib) { 
                dlclose(lib); 
                lib = NULL; 
            }

            lib = dlopen(path, RTLD_LAZY);
            if (!lib) {
                fprintf(stderr, "dlopen failed: %s\n", dlerror());
                continue;
            }

            gcd_ptr = (gcd_func)dlsym(lib, "gcd");
            pi_ptr  = (pi_func)dlsym(lib, "pi");

            if (!gcd_ptr || !pi_ptr) {
                fprintf(stderr, "dlsym failed\n");
                dlclose(lib);
                lib = NULL;
                gcd_ptr = pi_ptr = NULL;
            } else {
                printf("Switched to %s\n", path);
            }
        } else if (cmd == '1') {
            int a, b;
            if (sscanf(line, "1 %d %d", &a, &b) == 2 && gcd_ptr) {
                printf("gcd(%d, %d) = %d\n", a, b, gcd_ptr(a, b));
            } else if (!gcd_ptr) {
                printf("No library loaded. Use '0 <path>' first.\n");
            }
        } else if (cmd == '2') {
            int k;
            if (sscanf(line, "2 %d", &k) == 1 && pi_ptr) {
                printf("pi(%d) = %f\n", k, pi_ptr(k));
            } else if (!pi_ptr) {
                printf("No library loaded. Use '0 <path>' first.\n");
            }
        }
    }
    if (lib) dlclose(lib);
    return 0;
}

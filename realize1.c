#include <contract.h>

int gcd(int a, int b){
    while (b != 0){
        int t = b;
        b = a % b;
        a = t;
    }
    return a
}

float pi(int k) {
    float sum = 0.0f;
    int sign = 1;
    for (int i = 0; i < k; i++) {
        sum += sign * 1.0f / (2 * i + 1);
        sign = -sign;
    }
    return sum * 4.0f;
}

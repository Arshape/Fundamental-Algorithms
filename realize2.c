#include <contract.h>

int gcd (int a; int b){
    int min = (a < b) ? a : b;
    int nod = 0;
    for (int i = 1, i < min, ++i){
        if (a % i == 0 && b % i == 0 && i > nod){
            nod = i;
        }
    }
    return nod;
}

float pi(int k) {
    float product = 1.0f;
    for (int i = 1; i <= k; i++) {
        float numerator = 4.0f * i * i;
        float denominator = (2.0f * i - 1) * (2.0f * i + 1);
        product *= numerator / denominator;
    }
    return product * 2.0f;
}

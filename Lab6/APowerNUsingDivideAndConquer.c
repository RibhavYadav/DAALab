#include<stdio.h>
#include<stdlib.h>

long long int power(int base, int exp) {
    if (exp == 0) {
        return 1;
    }
    long long int val = power(base, exp / 2);
    if (exp % 2 == 0)
        return val * val;
    else
        return base * val * val;
}

void main() {
    int base = rand() % 50 + 1, exp = rand() % 10 + 1;
    printf("%d ^ %d is %lld", base, exp, power(base, exp));
}

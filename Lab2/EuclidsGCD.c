#include<stdio.h>
#include<stdlib.h>

int GCD(int m, int n) {
    if (!n)
        return m;
    GCD(n, m % n);
}

void main() {
    int n1, n2;
    for (int i = 0; i < 50; i++) {
        n1 = rand() * rand();
        n2 = rand() * rand();
        printf("%d, %d: %d\n", n1, n2, GCD(n1, n2));
    }
}

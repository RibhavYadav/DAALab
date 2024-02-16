#include<stdio.h>

long int fib(int n) {
    if (n == 1) {
        return 0;
    } else if (n == 2) {
        return 1;
    } else {
        return fib(n - 1) + fib(n - 2);
    }
}

void main() {
    int num;
    printf("Enter num: ");
    scanf("%d", &num);
    int fibnum = fib(num);
    printf("%d", fibnum);
}

#include<stdio.h>
#include<stdbool.h>

int factorial(int n) {
    int fact = 1;
    for (int i = n; i > 0; i--) {
        fact *= i;
    }
    return fact;
}

bool isStrong(int n) {
    int sum = 0;
    for (int i = n; i > 0; i /= 10) {
        sum += factorial(n % 10);
    }
    return n == sum;
}

void deleteStrong(int *arr, int n, int size) {
    if (n < size) {
        if (isStrong(arr[n])) {
            arr[n] = 0;
        }
        deleteStrong(arr, n + 1, size);
    }
}

void main() {
    int arr[5] = {1, 2, 143, 531, 1223};
    deleteStrong(arr, 0, 5);
    for (int i = 0; i < 5; i++) {
        if (arr[i] != 0) {
            printf("%d ", arr[i]);
        }
    }
}

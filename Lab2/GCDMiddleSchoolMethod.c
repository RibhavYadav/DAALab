#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int *sieve(int n) {
    //Finds prime numbers smaller than vertices
    int arr[n], *list = calloc(n, sizeof(int));
    for (int i = 2; i < n; i++)
        arr[i] = 1;
    for (int i = 2; i < sqrt(n); i++) {
        if (arr[i] != 0) {
            for (int j = i * i; j <= n; j += i) {
                arr[j] = 0;
            }
        }
    }
    for (int i = 0, j = 2; j < n; j++) {
        if (arr[j] != 0) {
            list[i++] = arr[j];
        }
    }
    return list;
}

int *primeFactors(int n) {
    int *factors = calloc(n, sizeof(int));
    int *list = sieve(n);
    for (int i = 2, j = 0; list[i - 2] * list[i - 2] <= n; i++) {
        while (n % i == 0) {
            factors[j++] = i;
            n /= i;
        }
    }
    return factors;
}

void GCD(int m, int n) {
    int *F1 = primeFactors(m), *F2 = primeFactors(n);
    int L1 = sizeof(F1) / sizeof(int), L2 = sizeof(F2) / sizeof(int);
    int k = 0, result[n], gcd = 1, i = 0, j = 0;
    while (i < L1 && j < L2) {
        if (F1[i] > F2[j]) {
            j++;
        } else if (F1[i] < F2[j]) {
            i++;
        } else {
            int flag = 0;
            for (int x = 0; x < k; x++) {
                if (result[x] == F1[i]) {
                    flag++;
                }
            }
            if (flag == 0) {
                result[k] = F1[i];
                k++;
            }
            i++;
            j++;
        }
    }
    for (int i = 0; i < n && result[i] != 0; i++)
        gcd *= result[i];
    printf("GCD is %d", gcd);
}

void main() {
    GCD(21, 7);
}

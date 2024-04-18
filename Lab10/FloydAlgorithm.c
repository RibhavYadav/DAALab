#include<stdio.h>
#include<stdlib.h>

#define size 5
int closure[size][size];

void init() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j)
                closure[i][j] = 0;
            else
                closure[i][j] = rand() % 100;
        }
    }
}

int min(int a, int b) {
    return a > b ? b : a;
}

void floyd() {
    for (int k = 0; k < size; k++) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                closure[i][j] = min(closure[i][j], closure[i][k] + closure[k][j]);
            }
        }
    }
}

void printClosure() {
    printf("\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", closure[i][j]);
        }
        printf("\n");
    }
}

void main() {
    init();
    printClosure();
    floyd();
    printClosure();
}

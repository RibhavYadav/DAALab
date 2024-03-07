#include<stdio.h>
#include<stdlib.h>

#define size 5

int **initializeMatrix(int **matrix) {
    matrix = calloc(size * size, sizeof(int *));
    for (int i = 0; i < size; i++) {
        matrix[i] = calloc(size, sizeof(int));
        for (int j = 0; j < size; j++) {
            matrix[i][j] = rand() % 1000 + 1;
        }
    }
    return matrix;
}

void printMatrix(int **matrix) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int **multiplyMatrix(int **matA, int **matB) {
    int **result = (int **) calloc(size * size, sizeof(int *));
    for (int i = 0; i < size; i++) {
        result[i] = calloc(size, sizeof(int));
        for (int j = 0; j < size; j++) {
            result[i][j] = 0;
            for (int k = 0; k < size; k++) {
                result[i][j] += (matA[i][k] * matB[k][j]);
            }
        }
    }
    return result;
}

void main() {
    int **matA = NULL, **matB = NULL, **matC;
    matA = initializeMatrix(matA);
    matB = initializeMatrix(matB);
    matC = multiplyMatrix(matA, matB);
    printMatrix(matC);
}

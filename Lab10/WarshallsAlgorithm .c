#include<stdio.h>
#include<time.h>

#define size 100
int closure[size][size][size] = {
        {
                {0, 1, 0, 0},
                {0, 0, 0, 1},
                {0, 0, 0, 0},
                {1, 0, 1, 0}
        }
};

void warshall() {
    for (int k = 0; k < size; k++) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (k == 0)
                    closure[k][i][j] = closure[k][i][j] || (closure[k][i][k] && closure[k][k][j]);
                else
                    closure[k][i][j] = closure[k - 1][i][j] || (closure[k - 1][i][k] && closure[k - 1][k][j]);
            }
        }
    }
}


void printClosure() {
    for (int i = 1; i < size; i++) {
        printf("R(%d)\n", i);
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                printf("%d ", closure[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

void main() {
    clock_t st, ed;
    st = clock();
    warshall();
    ed = clock();
    double tt = (double) (ed - st) / CLOCKS_PER_SEC;
    printf("Time taken: %f\n", tt);
    printf("Transitive closure: \n");
    printClosure();
}

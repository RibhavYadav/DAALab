#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int fact(int n) {
    return n <= 1 ? 1 : n * fact(n - 1);
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void generatePermutations(int run[N], int totalRuns) {
    for (int i = 0; i < N; i++)
        run[i] = i; // Initial permutation
    for (int i = 0; i < totalRuns; i++) { //Generating other permutations
        // Start from 2nd last element and move towards start of array
        // Find the index j such that run[j] > run[j+1]
        int j = N - 2;
        while (j >= 0 && run[j] > run[j + 1])
            j--;
        if (j == -1)
            break;
        // Find largest k such that run[k] < run[j]
        int k = N - 1;
        while (run[j] > run[k])
            k--;
        // Swap elements at j and k
        swap(&run[j], &run[k]);
        int r = N - 1, s = j + 1;
        // Reverse elements after index j
        while (r > s)
            swap(&run[s++], &run[r--]);
    }
}

void minCost(int costMatrix[N][N]) {
    int minCost = __INT_MAX__, minAssignment[N], tempCost;
    int totalRuns = fact(N), run[N];
    generatePermutations(run, totalRuns);
    for (int i = 0; i < totalRuns; i++) {
        tempCost = 0;
        for (int j = 0; j < N; j++)
            tempCost += costMatrix[j][run[j]];
        if (tempCost < minCost) {
            minCost = tempCost;
            for (int k = 0; k < N; k++)
                minAssignment[k] = run[k];
        }
    }
    printf("Minimum Cost: %d\n", minCost);
    printf("Assignments:\n");
    for (int i = 0; i < N; i++)
        printf("Worker %d -> Task %d\n", i + 1, minAssignment[i] + 1);
}

int main() {
    srand(time(NULL));
    clock_t start, end;
    int costMatrix[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            costMatrix[i][j] = rand();
    start = clock();
    minCost(costMatrix);
    end = clock();
    double tt = (double) (end - start) / CLOCKS_PER_SEC;
    printf("%f", tt);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include<time.h>

#define N 50 // Number of workers and tasks

// 0.078, 0.212, 0.305, 0.390
// Function to calculate fact
long long int fact(long long int n) {
    return n <= 1 ? 1 : n * fact(n - 1);

}

// Function to find the minimum cost
void minCost(long long int costMatrix[N][N]) {
    long long int minCost = INT_MAX, minAssignment[N];
    long long int i, j, k, tempCost;
// Generate all permutations of assignments
    long long int totalRuns = fact(N), run[N];
    for (i = 0; i < N; i++)
        run[i] = i;
    for (i = 0; i < totalRuns; i++) {
        tempCost = 0;
        for (j = 0; j < N; j++) {
            tempCost += costMatrix[j][run[j]];
        }
        if (tempCost < minCost) {
            minCost = tempCost;
            for (k = 0; k < N; k++)
                minAssignment[k] = run[k];
        }
// Generate the next run
        j = N - 2;
        while (j >= 0 && run[j] > run[j + 1])
            j--;
        if (j == -1)
            break;
        k = N - 1;
        while (run[j] > run[k])
            k--;
// Swap run[j] and run[k]
        long long int temp = run[j];
        run[j] = run[k];
        run[k] = temp;
// Reverse the elements from j+1 to N-1
        long long int r = N - 1;
        long long int s = j + 1;
        while (r > s) {
            temp = run[s];
            run[s] = run[r];
            run[r] = temp;
            r--;
            s++;
        }
    }
// Prlong long int the minimum cost and assignment
    printf("Minimum Cost: %d\n", minCost);
    printf("Assignments:\n");
    for (i = 0; i < N; i++)
        printf("Worker %d -> Task %d\n", i + 1, minAssignment[i] + 1);
}

long long int main() {
    clock_t start, end;
    long long int costMatrix[N][N];
    for (long long int i = 0; i < N; i++) {
        for (long long int j = 0; j < N; j++) {
            costMatrix[i][j] = rand();
        }
    }
    start = clock();
    minCost(costMatrix);
    end = clock();
    double tt = (double) (end - start) / CLOCKS_PER_SEC;
    printf("%f", tt);
    return 0;
}

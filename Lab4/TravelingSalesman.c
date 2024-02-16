#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 6
int minCost = INT_MAX;
int minPath[N];

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int cost(int graph[N][N], int path[N]) {
    int cost = 0;
    for (int i = 0; i < N - 1; i++) {
        cost += graph[path[i]][path[i + 1]];
    }
    cost += graph[path[N - 1]][path[0]];
    return cost;
}

// Function to find the minimum cost path using brute force method
void calcPath(int graph[N][N], int path[N], int start, int end) {
    if (start == end - 1) {
        int currentCost = cost(graph, path);
        if (currentCost < minCost) {
            minCost = currentCost;
            for (int i = 0; i < N; i++) {
                minPath[i] = path[i];
            }
        }
    } else {
        for (int i = start; i < end; i++) {
            swap(&path[start], &path[i]);
            calcPath(graph, path, start + 1, end);
            swap(&path[start], &path[i]); // Backtrack
        }
    }
}

int main() {
    clock_t start, end;
    int graph[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            graph[i][j] = i == j ? 1 : rand() % 100;
        }
    }
    int path[N]; // Store the current path
    for (int i = 0; i < N; i++)
        path[i] = i;
    start = clock();
    calcPath(graph, path, 0, N);
    end = clock();
    double tt = (double) (end - start) / CLOCKS_PER_SEC;
    printf("Minimum Cost: %d and time: %f\n", minCost, tt);
    printf("Path: ");
    for (int i = 0; i < N; i++)
        printf("%d -> ", minPath[i] + 1);
    printf("%d\n", minPath[0] + 1);
    return 0;
}

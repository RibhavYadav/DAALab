#include <time.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define size 1000

int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < size; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void printSolution(int dist[]) {
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < size; i++)
        printf("%d \t\t\t\t %d\n", i, dist[i]);
}

void dijkstra(int graph[size][size], int src) {
    int dist[size];
    bool sptSet[size];

    for (int i = 0; i < size; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    dist[src] = 0;

    for (int count = 0; count < size - 1; count++) {
        int u = minDistance(dist, sptSet);

        sptSet[u] = true;

        for (int v = 0; v < size; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    //printSolution(dist);
}

void main() {
    int graph[size][size];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int val = rand() % 100;
            if (i == j)
                graph[i][j] = 0;
            else {
                graph[i][j] = val;
                graph[j][i] = val;
            }
        }
    }
    clock_t start, end;
    start = clock();
    dijkstra(graph, 5);
    end = clock();
    double tt = (double) (end - start) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f", tt);
}

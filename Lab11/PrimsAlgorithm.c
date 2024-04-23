#include<stdio.h>
#include<stdlib.h>

#define size 10 // Number of vertices

typedef struct edge {
    int u, v, w;
} edge;

int adjacencyMatrix[size][size], vertices[size];
edge edgeArray[size * size], MST[size];

void init() {
    int k = 0;
    for (int i = 0; i < size; i++) {
        vertices[i] = 0;
        for (int j = 0; j < size; j++) {
            adjacencyMatrix[i][j] = adjacencyMatrix[j][i] = (i == j) ? 0 : rand() % 100 + 10;
            printf("%d ", adjacencyMatrix[i][j]);
            if (adjacencyMatrix[i][j] != 0) {
                edgeArray[k].u = i;
                edgeArray[k].v = j;
                edgeArray[k].w = adjacencyMatrix[i][j];
                k++; // Increment k by 1 for each edge
            }
        }
        printf("\n");
    }
}

int minEdge() {
    int minWeight = edgeArray[0].w, minIndex = 0;
    for (int i = 1; i < size * size; i++) {
        if (minWeight > edgeArray[i].w && vertices[edgeArray[i].u] == 1 && vertices[edgeArray[i].v] == 0) {
            minWeight = edgeArray[i].w;
            minIndex = i;
        }
    }
    return minIndex;
}

void prims() {
    vertices[0] = 1; // Mark the first vertex as visited
    for (int i = 0; i < size; i++) { // Loop size - 1 times
        edge temp = edgeArray[minEdge()];
        vertices[temp.v] = 1; // Mark the visited vertex
        MST[i] = temp;
    }
}

void main() {
    init();
    prims();
    for (int i = 0; i < size - 1; i++) { // Loop size - 1 times to print MST
        printf("%d %d %d\n", MST[i].u, MST[i].v, MST[i].w);
    }
}

#include<stdio.h>

#define size 5
int adjMatrix[size][size];

void initialize() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(int node1, int node2) {
    adjMatrix[node1][node2] = 1;
    adjMatrix[node2][node1] = 1;
}

void printAdjMatrix() {
    for (int i = 0; i < size; i++) {
        printf("%d: ", i);
        for (int j = 0; j < size; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void main() {
    initialize();
    int n1, n2;
    for (int i = 0; i < size; i++) {
        printf("Enter node:");
        scanf("%d", &n1);
        printf("Enter node:");
        scanf("%d", &n2);
        addEdge(n1, n2);
    }
    printAdjMatrix();
}

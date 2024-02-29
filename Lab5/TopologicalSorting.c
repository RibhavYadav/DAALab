#include<stdio.h>

#define size 5
int stack[size], visited[size], top = -1;
int adjMatrix[size][size] = {
        {0, 1, 0, 0, 1},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 1, 0}
};

void topologicalSort(int node) {
    visited[node] = 1;
    for (int i = 0; i < size; i++) {
        if (adjMatrix[node][i] && !visited[i]) {
            topologicalSort(i);
        }
    }
    stack[++top] = node;
}

void main() {
    for (int i = 0; i < size; i++)
        visited[i] = 0;
    for (int i = 0; i < size; i++) {
        if (!visited[i]) {
            topologicalSort(i);
        }
    }
    printf("Topological Order is: \n");
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
}

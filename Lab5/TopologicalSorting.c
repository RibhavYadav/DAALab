#include<stdio.h>
#include<stdlib.h>

#define size 6
int stack[size], visited[size], top = 0;
int adjMat[size][size] = {
        {0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {1, 1, 1, 1, 0}
};

void topologicalSort(int node) {
    visited[node] = 1;
    for (int i = 0; i < size - 1; i++) {
        if (visited[i] == 0 && adjMat[node][i] == 1) {
            topologicalSort(i);

        }
    }
    stack[++top] = node;
}


void main() {
    for (int i = 0; i < size; i++) {
        visited[i] = 0;
    }
    for (int i = 0; i < size; i++) {
        if (visited[i] == 0) {
            topologicalSort(i);
        }
    }
    for (int i = size; i >= 1; i--) {
        printf("%d->", stack[i]);
    }
}

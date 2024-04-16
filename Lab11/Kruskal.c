#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define size 500
typedef struct edge {
    int u, v, w;
} edge;
typedef struct edgeList {
    edge list[size * size];
    int n;
} edgeList;

int costMatrix[size][size], vertices = size;
edgeList MST, eList;

void swapEdge(edge *a, edge *b) {
    edge temp = *a;
    *a = *b;
    *b = temp;
}

void sortEdges() {
    for (int i = 1; i < eList.n; i++) {
        for (int j = 0; j < eList.n - 1; j++) {
            if (eList.list[j].w > eList.list[j + 1].w)
                swapEdge(&eList.list[j], &eList.list[j + 1]);
        }
    }
}

int find(int belongs[], int vertex) {
    return belongs[vertex];
}

void applyUnion(int belongs[], int vertex1, int vertex2) {
    for (int i = 0; i < vertices; i++) {
        if (belongs[i] == vertex2) {
            belongs[i] == vertex1;
        }
    }
}

void kruskal() {
    int belongs[size * size], v1, v2;
    eList.n = 0;
    for (int i = 1; i < vertices; i++) {
        for (int j = 0; j < i; j++) {
            if (costMatrix[i][j] != 0) {
                eList.list[eList.n].u = i;
                eList.list[eList.n].v = j;
                eList.list[eList.n].w = costMatrix[i][j];
                eList.n++;
            }
        }
    }
    sortEdges();
    for (int i = 0; i < vertices; i++) {
        belongs[i] = i;
    }
    MST.n = 0;

    for (int i = 0; i < eList.n; i++) {
        v1 = find(belongs, eList.list[i].u);
        v2 = find(belongs, eList.list[i].v);
        if (v1 != v2) {
            MST.list[MST.n] = eList.list[i];
            MST.n = MST.n + 1;
            applyUnion(belongs, v1, v2);
        }
    }
}

void printMST() {
    int cost = 0;
    for (int i = 0; i < MST.n; i++) {
        printf("\n%d %d %d", MST.list[i].u, MST.list[i].v, MST.list[i].w);
        cost += MST.list[i].w;
    }
    printf("\nCost is: %d", cost);
}

void main() {
    clock_t start, end;
    int val;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j)
                costMatrix[i][j] = 0;
            else {
                val = rand() % 50;
                costMatrix[i][j] = val;
                costMatrix[j][i] = val;
            }
        }
    }
    start = clock();
    kruskal();
    end = clock();
    //printMST();
    double tt = (double) (end - start) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f", tt);
}

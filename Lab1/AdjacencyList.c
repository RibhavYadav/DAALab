#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};
typedef struct node *node;

struct graph {
    int vertices;
    node *adjList; // Pointer to an array of node's
};
typedef struct graph *graph;

node getNode(int data) {
    node temp = (node) malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

graph createGraph(int vertices) {
    graph gp = malloc(sizeof(graph));
    gp->vertices = vertices;
    gp->adjList = malloc(sizeof(node) * vertices);
    for (int i = 0; i < vertices; i++) {
        gp->adjList[i] = 0;
    }
    return gp;
}

void addEdge(graph gp, int n1, int n2) {
    node node1 = getNode(n1);
    node node2 = getNode(n2);
    gp->adjList[n1] = node1;
    gp->adjList[n2] = node2;
    node1->next = gp->adjList[n2];
    node2->next = gp->adjList[n1];
}

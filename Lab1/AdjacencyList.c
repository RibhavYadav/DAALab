#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};
typedef struct node *Node;

struct graph {
    int vertices;
    Node *adjList; // Pointer to an array of Node's
};
typedef struct graph *graph;

Node getNode(int data) {
    Node temp = (Node) malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

graph createGraph(int vertices) {
    graph gp = malloc(sizeof(graph));
    gp->vertices = vertices;
    gp->adjList = malloc(sizeof(Node) * vertices);
    for (int i = 0; i < vertices; i++) {
        gp->adjList[i] = 0;
    }
    return gp;
}

void addEdge(graph gp, int s, int d) {
    Node source = getNode(s);
    Node dest = getNode(d);
    source->next = gp->adjList[d];
    dest->next = gp->adjList[s];
    gp->adjList[s] = dest;
    gp->adjList[d] = source;
}

void printGraph(graph gp) {
    for (int i = 0; i < gp->vertices; i++) {
        Node temp = gp->adjList[i];
        printf("%d: ", i);
        while (temp != NULL) {
            printf("%d->", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void main() {
    graph gp = createGraph(5);
    for (int i = 0; i < 5; i++) {
        int n1, n2;
        printf("Enter Node: ");
        scanf("%d", &n1);
        printf("Enter Node: ");
        scanf("%d", &n2);
        addEdge(gp, n1, n2);
    }
    printGraph(gp);
}

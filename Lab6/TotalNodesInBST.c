#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node {
    int data;
    struct node *lChild, *rChild;
} *root = NULL;

typedef struct node *Node;
int totalNodes = 0;


Node getNode(int data) {
    Node temp = malloc(sizeof(Node));
    temp->data = data;
    temp->lChild = NULL;
    temp->rChild = NULL;
    return temp;
}

Node insert(Node parent, int data) {
    if (parent == NULL) {
        Node temp = getNode(data);
        parent = temp;
    } else if (data > parent->data) {
        parent->rChild = insert(parent->rChild, data);
    } else {
        parent->lChild = insert(parent->lChild, data);
    }
    return parent;
}

void inOrder(Node parent) {
    if (parent != NULL) {
        totalNodes += 1;
        inOrder(parent->lChild);
        printf("%d ", parent->data);
        inOrder(parent->rChild);
    }
}

void main() {
    for (int i = 0; i < 15; i++) {
        root = insert(root, rand() % 100 + 1);
    }
    inOrder(root);
    printf("\nTotal nodes are: %d", totalNodes);
}

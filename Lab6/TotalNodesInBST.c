#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node {
    int data;
    struct node *lChild, *rChild;
} *root = NULL;

typedef struct node *node;
int totalNodes = 0;


node getNode(int data) {
    node temp = malloc(sizeof(node));
    temp->data = data;
    temp->lChild = NULL;
    temp->rChild = NULL;
    return temp;
}

node insert(node parent, int data) {
    if (parent == NULL) {
        node temp = getNode(data);
        parent = temp;
    } else if (data > parent->data) {
        parent->rChild = insert(parent->rChild, data);
    } else {
        parent->lChild = insert(parent->lChild, data);
    }
    return parent;
}

void inorder(node parent) {
    if (parent != NULL) {
        totalNodes += 1;
        inorder(parent->lChild);
        printf("%d ", parent->data);
        inorder(parent->rChild);
    }
}

void main() {
    for (int i = 0; i < 15; i++) {
        root = insert(root, rand() % 100 + 1);
    }
    inorder(root);
    printf("\nTotal nodes are: %d", totalNodes);
}

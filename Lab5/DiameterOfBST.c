#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *lChild, *rChild;
} *root = NULL;

typedef struct node *node;

node getNode(int data) {
    node temp = (node) malloc(sizeof(node));
    temp->data = data;
    temp->rChild = NULL;
    temp->lChild = NULL;
    return temp;
}

node insert(node parent, int data) {
    if (parent == NULL) {
        parent = getNode(data);
    } else if (data > parent->data) {
        parent->rChild = insert(parent->rChild, data);
    } else if (data <= parent->data) {
        parent->lChild = insert(parent->lChild, data);
    }
    return parent;
}

int max(int num1, int num2) {
    return (num1 > num2) ? num1 : num2;
}

int height(node parent) {
    if (parent == NULL)
        return 0;
    int maxHeight = max(height(parent->lChild), height(parent->rChild));
    return 1 + maxHeight;
}

int diameter(node parent) {
    if (parent == NULL)
        return 0;
    int lHeight = height(parent->lChild), rHeight = height(parent->rChild);
    int lDiameter = diameter(parent->lChild), rDiameter = diameter(parent->rChild);
    return max(lHeight + rHeight + 1, max(lDiameter, rDiameter));
}

void main() {
    int choice = -1, data;
    while (choice != 0) {
        printf("Enter data: ");
        scanf("%d", &data);
        root = insert(root, data);
        printf("Continue: ");
        scanf("%d", &choice);
    }
    printf("Diameter of tree is: %d", diameter(root));
}

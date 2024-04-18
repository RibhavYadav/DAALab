#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *lChild, *rChild;
} *root = NULL;

typedef struct node *Node;

Node getNode(int data) {
    // Create a Node with the given value as it's data and returns it's memory address
    Node temp = (Node) malloc(sizeof(Node));
    temp->data = data;
    temp->rChild = NULL;
    temp->lChild = NULL;
    return temp;
}

Node insert(Node parent, int data) {
    if (parent == NULL) {
        // If current Node does not exist create a Node with the given data
        parent = getNode(data);
    } else if (data > parent->data) {
        // If the given data is greater than the current Node's value then insert in the rChild subtree
        parent->rChild = insert(parent->rChild, data);
    } else if (data <= parent->data) {
        // If the given data is lesser than the current Node's value then insert in the lChild subtree
        parent->lChild = insert(parent->lChild, data);
    }
    return parent;
}

int max(int num1, int num2) {
    return num1 > num2 ? num1 : num2;
}

int height(Node parent) {
    // Recursively calculates the height of a given Node
    if (parent == NULL)
        return 0;
    // Height of a given Node is 1 + the largest height of it's subtrees
    int maxHeight = max(height(parent->lChild), height(parent->rChild));
    return 1 + maxHeight;
}

void balanceFactor(Node parent) {
    // Balance Factor of a Node is given by the height of the lChild subtree - height of the rChild subtree
    if (parent != NULL) {
        int factor = height(parent->lChild) - height(parent->rChild);
        printf("Node: %d Balance Factor: %d\n", parent->data, factor);
        balanceFactor(parent->lChild);
        balanceFactor(parent->rChild);
    }
}

void main() {
    int size, elm;
    printf("Enter size: ");
    scanf("%d", &size);
    while (size != 0) {
        elm = rand() % 1000 + 1;
        root = insert(root, elm);
        size--;
    }
    balanceFactor(root);
}

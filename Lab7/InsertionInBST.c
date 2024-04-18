#include<stdio.h>
#include<stdlib.h>
#include<time.h>

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

void preOrder(Node parent) {
    // Print the current Node then recursively print the lChild subtree and then the rChild subtree
    if (parent != NULL) {
        printf("%d ", parent->data);
        preOrder(parent->lChild);
        preOrder(parent->rChild);
    }
}

void inOrder(Node parent) {
    // Print the lChild subtree of the given Node, then the Node itself and finally the rChild subtree
    if (parent != NULL) {
        inOrder(parent->lChild);
        printf("%d ", parent->data);
        inOrder(parent->rChild);
    }
}

void postOrder(Node parent) {
    // Print the lChild subtree and then the rChild subtree of the given Node before printing the given Node
    if (parent != NULL) {
        postOrder(parent->lChild);
        postOrder(parent->rChild);
        printf("%d ", parent->data);
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
    double tt;
    clock_t st, ed;
    printf("Preorder: \n");
    st = clock();
    preOrder(root);
    ed = clock();
    tt = (double) (ed - st) / CLOCKS_PER_SEC;
    printf("\nTime taken is: %f", tt);
    printf("\nInorder: \n");
    st = clock();
    inOrder(root);
    ed = clock();
    tt = (double) (ed - st) / CLOCKS_PER_SEC;
    printf("\nTime taken is: %f", tt);
    printf("\nPostorder: \n");
    st = clock();
    postOrder(root);
    ed = clock();
    tt = (double) (ed - st) / CLOCKS_PER_SEC;
    printf("\nTime taken is: %f", tt);
}

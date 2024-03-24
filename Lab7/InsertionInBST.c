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

void preorder(node parent) {
    if (parent != NULL) {
        printf("%d ", parent->data);
        preorder(parent->lChild);
        preorder(parent->rChild);
    }
}

void inorder(node parent) {
    if (parent != NULL) {
        inorder(parent->lChild);
        printf("%d ", parent->data);
        inorder(parent->rChild);
    }
}

void postorder(node parent) {
    if (parent != NULL) {
        postorder(parent->lChild);
        postorder(parent->rChild);
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
    printf("Preorder: \n");
    postorder(root);
    printf("\nInorder: \n");
    inorder(root);
    printf("\nPostorder: \n");
    postorder(root);
}

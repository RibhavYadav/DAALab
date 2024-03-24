#include<stdio.h>
#include<stdlib.h>

struct node {
    int data, nodeHeight;
    struct node *lChild, *rChild;
} *root = NULL;

typedef struct node *node;

node getNode(int data) {
    node temp = (node) malloc(sizeof(node));
    temp->data = data;
    temp->rChild = NULL;
    temp->lChild = NULL;
    temp->nodeHeight = 1;
    return temp;
}

int max(int num1, int num2) {
    return num1 > num2 ? num1 : num2;
}

int height(node parent) {
    if (parent == NULL)
        return 0;
    int maxHeight = max(height(parent->lChild), height(parent->rChild));
    return 1 + maxHeight;
}

int balanceFactor(node parent) {
    if (parent == NULL)
        return 0;
    return height(parent->lChild) - height(parent->rChild);
}

node rotateRight(node node1) {
    node tempNode1 = node1->lChild, tempNode2 = node1->rChild;
    tempNode1->rChild = node1;
    node1->lChild = tempNode2;
    node1->nodeHeight = height(node1);
    tempNode1->nodeHeight = height(tempNode1);
    return tempNode1;
}

node rotateLeft(node node1) {
    node tempNode1 = node1->rChild, tempNode2 = node1->lChild;
    tempNode1->lChild = node1;
    node1->rChild = tempNode2;
    node1->nodeHeight = height(node1);
    tempNode1->nodeHeight = height(tempNode1);
    return tempNode1;
}

node insert(node parent, int data) {
    if (parent == NULL) {
        parent = getNode(data);
    } else if (data > parent->data) {
        parent->rChild = insert(parent->rChild, data);
    } else if (data <= parent->data) {
        parent->lChild = insert(parent->lChild, data);
    }
    parent->nodeHeight = height(parent);
    int bf = balanceFactor(parent);
    if (bf > 1) {
        if (data < parent->lChild->data) {
            return rotateRight(parent); // Right Right Case
        } else {
            parent->lChild = rotateLeft(parent->lChild);
            return rotateRight(parent); // Right Left Case
        }
    } else if (bf < -1) {
        if (data > parent->rChild->data) {
            return rotateLeft(parent); // Left Right Case
        } else {
            parent->rChild = rotateRight(parent->rChild);
            return rotateLeft(parent); // Left Left Case
        }
    }
    return parent;
}

void inorder(node parent) {
    if (parent != NULL) {
        inorder(parent->lChild);
        printf("%d ", parent->data);
        inorder(parent->rChild);
    }
}

void main() {
    int size, elm;
    printf("Enter size: ");
    scanf("%d", &size);
    while (size != 0) {
        elm = rand() % 1000 + 1;
        root = insert(root, elm);
        inorder(root);
        printf("\n %d \n", elm);
        size--;
    }
}

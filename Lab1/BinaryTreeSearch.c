#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node {
    int data;
    struct node *lChild, *rChild;
} *root = NULL;

typedef struct node *node;

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

bool search(node parent, int data) {
    if (parent != NULL) {
        if (parent->data == data) {
            return true;
        } else {
            if (search(parent->lChild, data)) {
                return true;
            }
            if (search(parent->rChild, data)) {
                return true;
            }
        }
    }
    return false;
}


void main() {
    int choice = 0, val;
    do {
        printf("Choice:");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data:");
                scanf("%d", &val);
                root = insert(root, val);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &val);
                if (search(root, val)) {
                    printf("Data found\n");
                } else {
                    root = insert(root, val);
                    printf("Data not found\n");
                }
                break;
        }
    } while (choice != 0);
}

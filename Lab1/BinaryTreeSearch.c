#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node {
    int data;
    struct node *lChild, *rChild;
} *root = NULL;

typedef struct node *Node;

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

bool search(Node parent, int data) {
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

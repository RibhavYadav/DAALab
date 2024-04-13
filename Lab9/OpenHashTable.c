#include<stdio.h>
#include<stdlib.h>

#define size 6
struct node {
    int data;
    struct node *next;
} *start = NULL;

typedef struct node *node;
node hashTable[size];

void init() {
    for (int i = 0; i < size; i++) {
        hashTable[i] = NULL;
    }
}

node getNode(int value) {
    node newNode = (node) malloc(sizeof(node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insert(int data) {
    int key = data % size;
    if (hashTable[key] == NULL) {
        hashTable[key] = getNode(data);
    } else {
        node temp = hashTable[key];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = getNode(data);
    }
}

void printTable() {
    for (int i = 0; i < size; i++) {
        node temp = hashTable[i];
        printf("Key %d: ", i + 1);
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}


void main() {
    init();
    int data, inputs;
    printf("Amount of inputs: ");
    scanf("%d", &inputs);
    for (int i = 0; i < inputs; i++) {
        data = rand() % 100 + 1;
        insert(data);
    }
    printTable();
}

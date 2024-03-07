#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *prev, *next;
} *start = NULL;
typedef struct node *node;

node getNode(int data) {
    node temp = (node) malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

void insert(int data) {
    node temp = start;
    node val = getNode(data);
    if (start == NULL) {
        start = val;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = val;
        val->prev = temp;
    }
}

void insertAt(node val, int data) {
    node temp = start;
    if (start == NULL) {
        start->next = val;
        val->prev = start;
    } else {
        while (temp->data != data) {
            temp = temp->next;
        }
        val->next = temp->next;
        temp->next->prev = val;
        val->prev = temp;
        temp->next = val;
    }
}

void delete(node val) {
    if (val == start) {
        start = start->next;
        start->prev = NULL;
        free(val);
    } else if (val->next == NULL) {
        val = val->prev;
        free(val->next);
        val->next = NULL;
    } else {
        val->prev->next = val->next;
        val->next->prev = val->prev;
        free(val);
    }
}

void deleteValue(int data) {
    node temp = start;
    while (temp != NULL) {
        if (temp->data == data) {
            delete(temp);
        }
        temp = temp->next;
    }
}

void search(int data) {
    node temp = start;
    while (temp != NULL) {
        if (temp->data == data) {
            printf("Data found\n");
            return;
        }
        temp = temp->next;
    }
    printf("Data not found\n");
}

void display() {
    for (node temp = start; temp != NULL; temp = temp->next) {
        printf("%d ", temp->data);
    }
    printf("\n");
}

void main() {
    int choice = 0, val;
    printf("1.Insert\n2.Insert at\n3.Delete\n4.Search\n5.Display\n");
    do {
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data:");
                scanf("%d", &val);
                insert(val);
                break;
            case 2:
                printf("Enter data:");
                scanf("%d", &val);
                node temp = getNode(val);
                printf("Enter location:");
                scanf("%d", &val);
                insertAt(temp, val);
                break;
            case 3:
                printf("Enter data:");
                scanf("%d", &val);
                deleteValue(val);
                break;
            case 4:
                printf("Enter data:");
                scanf("%d", &val);
                search(val);
                break;
            case 5:
                display();
                break;
        }
    } while (choice != 0);
}

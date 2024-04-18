#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key, height;
    struct Node *lChild, *rChild;
} *root = NULL;

typedef struct Node *Node;

Node newNode(int key) {
    Node node = (Node) malloc(sizeof(node));
    node->key = key;
    node->lChild = NULL;
    node->rChild = NULL;
    node->height = 1;
    return (node);
}

int height(Node N) {
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

// Right rotate
Node rightRotate(Node y) {
    Node x = y->lChild;
    Node T2 = x->rChild;

    x->rChild = y;
    y->lChild = T2;

    y->height = max(height(y->lChild), height(y->rChild)) + 1;
    x->height = max(height(x->lChild), height(x->rChild)) + 1;

    return x;
}

// Left rotate
Node leftRotate(struct Node *x) {
    Node y = x->rChild;
    Node T2 = y->lChild;

    y->lChild = x;
    x->rChild = T2;

    x->height = max(height(x->lChild), height(x->rChild)) + 1;
    y->height = max(height(y->lChild), height(y->rChild)) + 1;

    return y;
}

// Get the balance factor
int getBalance(Node N) {
    if (N == NULL)
        return 0;
    return height(N->lChild) - height(N->rChild);
}

// Insert Node
Node insertNode(Node node, int key) {
    // Find the correct position to insertNode the Node and insertNode it
    if (node == NULL)
        return (newNode(key));
    if (key < node->key)
        node->lChild = insertNode(node->lChild, key);
    else if (key > node->key)
        node->rChild = insertNode(node->rChild, key);
    else
        return node;

    // Update the balance factor of each Node and
    // Balance the tree
    node->height = 1 + max(height(node->lChild), height(node->rChild));

    int balance = getBalance(node);
    if (balance > 1 && key < node->lChild->key)
        return rightRotate(node);

    if (balance < -1 && key > node->rChild->key)
        return leftRotate(node);

    if (balance > 1 && key > node->lChild->key) {
        node->lChild = leftRotate(node->lChild);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->rChild->key) {
        node->rChild = rightRotate(node->rChild);
        return leftRotate(node);
    }

    return node;
}

void inOrder(Node parent) {
    // Print the lChild subtree of the given Node, then the Node itself and finally the rChild subtree
    if (parent != NULL) {
        inOrder(parent->lChild);
        printf("%d ", parent->key);
        inOrder(parent->rChild);
    }
}

void main() {
    int size;
    printf("Enter size: ");
    scanf("%d", &size);
    for (int i = 0; i < size; i++) {
        int val = rand() % 100 + 1;
        root = insertNode(root, val);
    }
    inOrder(root);
}

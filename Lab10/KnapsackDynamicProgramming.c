#include<stdio.h>
#include<stdlib.h>

#define size 5
#define knapsackSize 10
int weights[size], values[size], table[size + 1][knapsackSize + 1];

void init() {
    for (int i = 0; i < size; i++) {
        weights[i] = rand() % 25 + 1;
        values[i] = rand() % 30 + 1;
    }
    for (int i = 0; i < size + 1; i++) {
        for (int j = 0; j < knapsackSize + 1; j++) {
            if (i == 0 || j == 0)
                table[i][j] = 0;
            else
                table[i][j] = -1;
        }
    }
}

int max(int a, int b) {
    return a > b ? a : b;
}

int knapsack(int items, int capacity) {
    int value;
    if (table[items][capacity] < 0) {
        if (capacity < weights[items]) {
            value = knapsack(items - 1, capacity);
        } else {
            value = max(knapsack(items - 1, capacity),
                        values[items] + knapsack(items - 1, capacity - weights[items]));
        }
        table[items][capacity] = value;
    }
    return table[items][capacity];
}

void main() {
    init();
    int value = knapsack(size - 1, knapsackSize);
    printf("%d", value);
}

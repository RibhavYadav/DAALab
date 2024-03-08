#include<stdio.h>
#include<stdlib.h>
#include<math.h>

size_t knapsack(size_t *weight, size_t *values, size_t capacity, size_t items) {
    size_t maxVal = 0, sequence = 0, totalWeight, totalValue, index, temp;
    for (int i = 1; i < pow(2, items); i++) {
        temp = i; // Bit array
        totalValue = 0;
        totalWeight = 0; // Value in current order
        index = 0;
        while (temp) {
            // Sum of elements in current permutation
            if (temp & 0x1) { // temp is bitwise AND'ed with 0x1 = 0000 0001
                // Index is used to track the current element being considered
                totalWeight += weight[index];
                totalValue += values[index];
            }
            index++;
            temp = temp >> 1; // Next permutation
        }
        if (totalWeight <= capacity && totalValue > maxVal) {
            maxVal = totalValue;
            sequence = i;
        }
    }
    return sequence;
}

void main() {
    size_t *values, *weights, items, idealSequence, capacity;
    printf("Enter the number of elements:");
    scanf("%zu", &items);
    values = (size_t *) calloc(items, sizeof(size_t));
    weights = (size_t *) calloc(items, sizeof(size_t));
    for (int i = 0; i < items; i++)
        weights[i] = rand() % 20 + 1;
    for (int i = 0; i < items; i++)
        values[i] = rand() % 50 + 10;
    printf("Please enter the Knapsack capacity:");
    scanf("%zu", &capacity);
    idealSequence = knapsack(weights, values, capacity, items);
    int i = 0;
    while (idealSequence) {
        if (idealSequence & 0x1) {
            printf("Item: %d Value: %zu\n", (i + 1), values[i]);
        }
        i++;
        idealSequence = idealSequence >> 1;
    }
}

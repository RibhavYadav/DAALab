#include<stdio.h>
#include<stdlib.h>

int *countingSort(int input[], int size) {
    // Get the size for the frequency array
    int minVal = input[0], maxVal = input[0];
    for (int i = 0; i < size; i++) {
        if (minVal > input[i])
            minVal = input[i];
        if (maxVal < input[i])
            maxVal = input[i];
    }
    int tempSize = maxVal - minVal + 1;
    // Allocate space for array
    int *frequency = (int *) calloc(tempSize, sizeof(int));
    int *sorted = (int *) calloc(size, sizeof(int));
    for (int i = 0; i < tempSize; i++) {
        // Initialize with 0
        frequency[i] = 0;
    }
    for (int i = 0; i < size; i++) {
        // Compute frequency
        frequency[input[i] - minVal]++;
    }
    for (int i = 1; i < tempSize; i++) {
        // Compute distribution
        frequency[i] += frequency[i - 1];
    }
    for (int i = size - 1; i >= 0; i--) {
        int temp = input[i] - minVal;
        sorted[frequency[temp] - 1] = input[i];
        frequency[temp]--;
    }
    return sorted;
}

void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void main() {
    int size;
    printf("Enter size:");
    scanf("%d", &size);
    int *arr = (int *) calloc(size, sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = rand();
    }
    printArray(arr, size);
    arr = countingSort(arr, size);
    printArray(arr, size);
    free(arr);
}

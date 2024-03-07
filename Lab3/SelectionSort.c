#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b) {
    // Swapping two elements
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int *array, int size) {
    // Prints entire array
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

void selectionSort(int *array, int size) {
    // Selects the minimum element and place's it at the start of the array in that iteration
    for (int i = 0; i < size - 1; i++) {
        // Assume starting element as minimum and take its index
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            // Compare the element at minIndex with the rest of the elements in the array
            if (array[j] < array[minIndex])
                // If the element at index j is smaller than the assumed minimum element, then update minIndex
                minIndex = j;
        }
        // Swap the smallest element with the element at the start of the current iteration
        swap(&array[i], &array[minIndex]);
    }
}

void main() {
    int *array, size;
    printf("Enter size:");
    scanf("%d", &size);
    array = (int *) calloc(size, sizeof(int));
    for (int i = 0; i < size; i++)
        array[i] = rand();
    printf("Array before swap:\n");
    printArray(array, size);
    selectionSort(array, size);
    printf("Array after swap:\n");
    printArray(array, size);
}

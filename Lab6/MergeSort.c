#include<stdio.h>
#include<stdlib.h>

void merge(int *array, int subArray1Index, int subArray2Index, int lastIndex) {
    // Copies of sub arrays are array[subArray1Index ... subArray2Index] and array[subArray2Index+1 ... lastIndex]
    int subArray1Length = subArray2Index - subArray1Index + 1, subArray2Length = lastIndex - subArray2Index;
    int subArray1[subArray1Length], subArray2[subArray2Length];
    for (int i = 0; i < subArray1Length; i++)
        subArray1[i] = array[subArray1Index + i];
    for (int i = 0; i < subArray2Length; i++)
        subArray2[i] = array[subArray2Index + 1 + i];
    // Compare elements of the sub arrays and copy them in the main array, k is used to track the main array i,j for the
    // sub arrays
    int k = subArray1Index, i, j;
    for (i = 0, j = 0; i < subArray1Length && j < subArray2Length;) {
        array[k++] = subArray1[i] <= subArray2[j] ? subArray1[i++] : subArray2[j++];
    }
    // Adding left over elements from the sub arrays
    while (i < subArray1Length) {
        array[k++] = subArray1[i++];
    }
    while (j < subArray2Length) {
        array[k++] = subArray2[j++];
    }
}

void mergeSort(int *array, int startIndex, int endIndex) {
    if (startIndex < endIndex) {
        int middleIndex = (startIndex + endIndex) / 2;
        // Sort left half of the array
        mergeSort(array, startIndex, middleIndex);
        // Sort right half of the array
        mergeSort(array, middleIndex + 1, endIndex);
        // Merge the sorted sub arrays
        merge(array, startIndex, middleIndex, endIndex);
    }
}

void printArray(int *array, int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

void main() {
    int *array, size;
    printf("Enter size:");
    scanf("%d", &size);
    array = (int *) malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
        array[i] = rand();
    printf("Array before swap:\n");
    printArray(array, size);
    mergeSort(array, 0, size - 1);
    printf("Array after swap:\n");
    printArray(array, size);
}

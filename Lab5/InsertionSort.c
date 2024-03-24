#include<stdio.h>
#include<stdlib.h>

void insertionSort(int *arr, int size) {
    int j;
    for (int i = 1; i < size; i++) {
        int elm = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > elm) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = elm;
    }
}

void printArray(int *array, int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

void main() {
    int size;
    printf("Enter size: ");
    scanf("%d", &size);
    int arr[size];
    for (int i = 0; i < size; i++)
        arr[i] = rand() % 100 + 1;
    printArray(arr, size);
    insertionSort(arr, size);
    printArray(arr, size);
}

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int opCount = 0;

void swap(int *num1, int *num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int partition(int *array, int start, int end) {
    // Partitions the array to call quicksort on, returns location of pivot
    // Pivot is at assumed to be at the end, i is one less than j i.e i  is one less than start
    int pivot = array[end], i = start - 1;
    for (int j = start; j < end; j++) {
        // If element is smaller than the pivot swap it with the element before it
        if (array[j] <= pivot) {
            opCount++;
            swap(&array[++i], &array[j]);
        }
    }
    // After the loop, swap the pivot with the element in the i+1'th position
    // This places the pivot in the correct position
    swap(&array[++i], &array[end]);
    return i;
}

void quickSort(int *array, int start, int end) { // Pass start as 0 and end as length of array - 1
    if (start < end) {
        int pivot = partition(array, start, end);
        // Sorting the sub arrays, +/- 1 as pivot is already in place
        quickSort(array, start, pivot - 1);
        quickSort(array, pivot + 1, end);
    }
}

void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void main() {
    // Creating an array of given size
    int size;
    clock_t start, end;
    printf("Enter size: ");
    scanf("%d", &size);
    int arr[size];
    // Assigning 'random' elements to the array
    for (int i = 0; i < size; i++) {
        arr[i] = rand();
    }
    start = clock();
    quickSort(arr, 0, size - 1);
    end = clock();
    double time = (double) (end - start) / CLOCKS_PER_SEC;
    printf("Opcount is %d, time is %f", opCount, time);
}

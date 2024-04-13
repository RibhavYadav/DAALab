#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void bottomUpHeap(int *heap, int size) {
    int k, v, heaps;
    for (int i = size / 2; i >= 0; i--) {
        k = i, v = heap[k], heaps = 0;
        while (heaps == 0 && (2 * k) <= size) {
            int j = 2 * k;
            if (j < size) {
                if (heap[j] < heap[j + 1])
                    j += 1;
            }
            if (v >= heap[j])
                heaps = 1;
            else {
                heap[k] = heap[j];
                k = j;
            }
        }
        heap[k] = v;
    }
}

void heapSort(int *heap, int size) {
    int sortedArray[size];
    bottomUpHeap(heap, size);
    for (int i = 0; i < size; i++) {
        sortedArray[size - i - 1] = heap[i];
        bottomUpHeap(heap + i + 1, size - i - 1);
    }
    printArray(sortedArray, size);
}

void main() {
    int size;
    printf("Enter size:");
    scanf("%d", &size);
    int arr[size];
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100 + 1;
    }
    printArray(arr, size);
    printf("Heap Sort is:\n");
    clock_t st, end;
    st = clock();
    heapSort(arr, size);
    end = clock();
    double tt = (double) (end - st) / CLOCKS_PER_SEC;
    printf("Time taken is: %f", tt);
}

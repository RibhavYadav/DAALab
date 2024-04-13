#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void heapify(int *heap, int heapSize, int index) {
    int largest = index, l = 2 * index, r = 2 * index + 1;
    if (l < heapSize && heap[l] > heap[largest])
        largest = l;
    if (r < heapSize && heap[r] > heap[largest])
        largest = r;
    if (largest != index) {
        swap(&heap[index], &heap[largest]);
        heapify(heap, heapSize, largest);
    }
}

int *topDownHeap(int array[], int size) {
    int heapSize = size + 1, *heap = (int *) calloc(heapSize, sizeof(int));
    for (int i = 0; i < heapSize; i++) {
        heap[i] = 0;
    }
    int i = 0;
    for (int j = 1; j < heapSize / 2; j++) {
        while (i < size) {
            if (heap[j] == 0) {
                heap[j] = array[i];
            } else if (heap[2 * j] == 0) {
                heap[2 * j] = array[i];
            } else if (heap[2 * j + 1] == 0) {
                heap[2 * j + 1] = array[i];
            } else
                break;
            i++;
        }
    }
    for (i = heapSize / 2; i > 0; i--) {
        heapify(heap, heapSize, i);
    }
    return heap;
}

void main() {
    int size;
    printf("Enter size:");
    scanf("%d", &size);
    int *arr = (int *) malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100 + 1;
    }
    printArray(arr, size);
    clock_t st, end;
    st = clock();
    int *heap = topDownHeap(arr, size);
    end = clock();
    printArray(heap, size + 1);
    double tt = (double) (end - st) / CLOCKS_PER_SEC;
    printf("Time taken is: %f", tt);
}

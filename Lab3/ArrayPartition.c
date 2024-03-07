#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool arrayPartition(int *arr, int size, int sum) {
    // Base cases
    if (sum == 0)
        return true;
    if (size == 0 && sum != 0) {
        return false;
    }
    // If the last element is greater than the sum then
    // find if it can be partitioned without the last element
    if (arr[size - 1] > sum) {
        return arrayPartition(arr, size - 1, sum);
    }
    // If the last element is not greater than the sum
    // (i.e the last element is less than or equal to the sum) check
    // if sum can be obtained by excluding the last element or by including the last element
    return arrayPartition(arr, size - 1, sum) || arrayPartition(arr, size - 1, sum - arr[size - 1]);

}

bool arraySum(int *arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    if (sum % 2 == 0)
        return arrayPartition(arr, size, sum / 2);
    return false;
}

void main() {
    int size;
    printf("Enter size:");
    scanf("%d", &size);
    int *arr = calloc(size, sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10 + 1;
    }
    if (arraySum(arr, size)) {
        printf("Array can be partitioned");
    } else {
        printf("Array cannot be partitioned");
    }
}

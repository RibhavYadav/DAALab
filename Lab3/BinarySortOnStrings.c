#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void swapStrings(char **str1, char **str2) {
    char *temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}

void sortStrings(char **arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                swapStrings(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void printArray(char **arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%s \n", arr[i]);
    }
}

void main() {
    char *strings[] = {"certain", "programming", "proof", "info", "dynamic"};
    printf("Before sort:\n");
    printArray(strings, 5);
    sortStrings(strings, 5);
    printf("After sort:\n");
    printArray(strings, 5);
}

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void main() {
    clock_t start, e;
    int i, j, n, temp, opcount = 0;
    printf("Enter length of array\n");
    scanf("%d", &n);
    int a[n];
    printf("Enter array elements\n");
    for (i = 0; i < n; i++)
        a[i] = rand();
    printf("The array before sorting is :\n");
    for (i = 0; i < n; i++)
        printf("%d \t", a[i]);
    printf("\n");
    start = clock();
    //bubble sort
    for (i = 0; i < (n - 1); i++) {
        for (j = 0; j < (n - i - 1); j++) {
            opcount++;
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    printf("The array after sorting is :\n");
    for (i = 0; i < n; i++)
        printf("%d \t", a[i]);
    e = clock();
    double tot = (double) (e - start) / CLOCKS_PER_SEC;
    printf("\nTotal time taken = %ld\n", tot);
    printf("opcount is : %d", opcount);
}

#include<stdio.h>

void towerOfHanoi(int n, char source, char destination, char auxiliary) {
    if (n == 1) {
        printf("\n Move disk 1 from rod %c to rod %c", source, destination);
        return;
    }
    towerOfHanoi(n - 1, source, auxiliary, destination);
    printf("\n Move disk %d from rod %c to rod %c", n, source, destination);
    towerOfHanoi(n - 1, auxiliary, destination, source);
}

void main() {
    int n = 4;
    towerOfHanoi(n, 'A', 'B', 'C');
}

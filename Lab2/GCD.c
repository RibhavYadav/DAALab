#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int GCD(int n, int m) {
    int min = n > m ? n : m;
    int ops = 0;
    while (min != 0) {
        ops++;
        if (n % min == 0) {
            if (m % min == 0) {
                return ops;
            } else {
                min--;
            }
        } else {
            min--;
        }
    }
}

int main() {
    FILE *fp = fopen("GCD.csv", "w+");
    fprintf(fp, "m + n, Basic operation, Time\n");
    clock_t start, end;
    for (int i = 0; i < 100; i++) {
        int m = random(), n = rand(), ops;
        start = clock();
        ops = GCD(n, m);
        end = clock();
        double time = (double) (end - start) / CLOCKS_PER_SEC;
        printf("%d, %d, %f\n", (m + n), ops, time);
        fprintf(fp, "%d, %d, %f\n", (m + n), ops, time);
    }
    fclose(fp);
    return 0;
}

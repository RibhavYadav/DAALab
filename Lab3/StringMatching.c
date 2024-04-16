#include<stdio.h>
#include<string.h>
#include<time.h>

long int basicop = 0;

long int StringMatch(char *str, char *substr) {
    int lenstr = strlen(str), lensubstr = strlen(substr);
    long int i, j;
    for (i = 0; i < lenstr - lensubstr; i++) {
        for (j = 0; j < lensubstr; j++) {
            basicop++;
            if (str[i + j] != substr[j])
                break;
        }
        if (j == lensubstr) {
            printf("Basic OP: %d\n", basicop);
            return i;
        }
    }
    return 0;
}

void main() {
    clock_t start, end;
    char s1[100000], s2[100];
    printf("Enter string: ");
    gets(s1);
    printf("Enter sub string: ");
    gets(s2);
    start = clock();
    long int match = StringMatch(s1, s2);
    end = clock();
    printf("Match found at %ld\n", match);
    double time_taken = (double) (end - start) / CLOCKS_PER_SEC;
    printf("Time taken is %e\nm+vertices is: %llu", time_taken, (strlen(s1) + strlen(s2)));
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define max 256

int maximum(int a, int b) {
    return a > b ? a : b;
}

int *badCharTable(char *text) {
    int n = strlen(text), *badTable = (int *) calloc(max, sizeof(int));
    for (int i = 0; i < max; i++) {
        badTable[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        badTable[(int) text[i]] = i;
    }
    return badTable;
}

void boyerMoore(char *text, char *pattern) {
    int m = strlen(pattern), n = strlen(text), shifts = 0;
    int *badTable = badCharTable(text);
    while (shifts <= (n - m)) {
        int j = m - 1; // Comparing from the end of the pattern (Right to left)
        while (j >= 0 && pattern[j] == text[shifts + j]) {
            // If Pattern matches reduce j
            j--;
        }
        if (j < 0) {
            printf("Pattern at: %d", shifts);
            return;
        } else {
            shifts += maximum(1, j - badTable[text[shifts + j]]);
        }
    }
}

void main() {
    char text[256], pattern[256];
    puts("Text:");
    gets(text);
    puts("Pattern:");
    gets(pattern);
    boyerMoore(text, pattern);
}

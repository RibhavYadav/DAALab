#include <stdio.h>
#include <string.h>

int MAX = 256;

int horspool(char text[], char pattern[], int shiftTable[]) {
    int i, n, m, k;
    n = strlen(text);
    m = strlen(pattern);
    i = m - 1;
    while (i < n) {
        k = 0;
        while ((k < m) && (pattern[m - 1 - k] == text[i - k]))
            k++;

        if (k == m)
            return i - m + 1;
        else
            i = i + shiftTable[text[i]];
    }
    return -1;
}

void getShiftTable(char pattern[], int text[]) {
    int m, i, j;
    m = strlen(pattern);
    for (i = 0; i < MAX; i++) {
        text[i] = m;
    }
    for (j = 0; j < m - 1; j++) {
        text[pattern[j]] = m - 1 - j;
    }
}


void main() {
    char text[MAX], pattern[MAX];
    int shiftTable[MAX], found;
    puts("Enter the source string : ");
    gets(text);
    puts("Enter the pattern string : ");
    gets(pattern);
    getShiftTable(pattern, shiftTable);
    found = horspool(text, pattern, shiftTable);
    if (found == -1)
        puts("\nMatching Substring not found.\n");
    else
        printf("\nMatching Substring found at position: %d\n", found + 1);
}

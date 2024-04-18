#include <stdio.h>
#include <string.h>

int MAX = 256, comp = 0;

int horspool(char text[], char pattern[], int shiftTable[]) {
    int k, textLength = strlen(text), patternLength = strlen(pattern), patternIndex = patternLength - 1;;
    while (patternIndex < textLength) {
        k = 0;
        comp++;
        // Comparing characters from the right hand side of the pattern
        while ((k < patternLength) && (pattern[patternLength - 1 - k] == text[patternIndex - k])) {
            // On Match increment k
            comp++;
            k++;
        }
        if (k == patternLength)
            return patternIndex - patternLength + 1;
        else
            patternIndex += shiftTable[text[patternIndex]];
    }
    return -1;
}

void getShiftTable(char pattern[], int shiftTable[]) {
    int m, i, j;
    m = strlen(pattern);
    for (i = 0; i < MAX; i++) {
        shiftTable[i] = m - 1;
    }
    for (j = 0; j < m - 1; j++) {
        shiftTable[pattern[j]] = m - j;
    }
}


void main() {
    char text[MAX], pattern[MAX];
    int shiftTable[MAX], found;
    puts("Enter the source string: ");
    gets(text);
    puts("Enter the pattern string: ");
    gets(pattern);
    getShiftTable(pattern, shiftTable);
    found = horspool(text, pattern, shiftTable);
    if (found == -1)
        puts("\nSubstring not found.\n");
    else
        printf("\nSubstring found at position: %d\n", found + 1);
    printf("Comparisons: %d", comp);
}

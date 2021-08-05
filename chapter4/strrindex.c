#include <stdio.h>
#include "utilities.h"

#define MAXLENGTH 100

int strrindex(char s[], char t[]);

char pattern[] = "Hello";

int main() {
    char line[MAXLENGTH];
    int count;
    int idx;

    while ((count = getLine(line, MAXLENGTH)) != 0) {
        if ((idx = strrindex(line, pattern)) != -1)
            printf("%d: %s", idx, line);
    }

    return 0;
}

int strrindex(char s[], char t[]) {
    int i, j, k;
    int r = -1;

    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            r = i;
    }

    return r;
}
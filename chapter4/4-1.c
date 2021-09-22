#include <stdio.h>

#define MAXLENGTH 100

int getline(char a[], int lim);
int strrindex(char s[], char t[]);

char pattern[] = "Hello";

int main() {
    char line[MAXLENGTH];
    int count;
    int idx;

    while ((count = getline(line, MAXLENGTH)) != 0)
        if ((idx = strrindex(line, pattern)) != -1)
            printf("%d: %s", idx, line);

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

int getline(char a[], int lim) {
    // lim is the number of all characters, including '\0'
    char c;
    int i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        a[i++] = c;

    if (c == '\n')
        a[i++] = c;
    a[i] = '\0';

    return i;
}
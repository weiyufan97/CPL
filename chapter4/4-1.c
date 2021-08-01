#include <stdio.h>

#define MAXLENGTH 100

int getline(char line[], int lim);
int strrindex(char s[], char t[]);

char pattern[] = "ould";

int main() {
    char line[MAXLENGTH];
    int count;
    int idx;

    while ((count = getline(line, MAXLENGTH)) != 0) {
        if ((idx = strrindex(line, pattern)) != -1)
            printf("%s %d\n", line, idx);
    }

    return 0;
}

int getline(char line[], int lim) {
    char ch;
    int i = 0;

    while ((ch = getchar()) != EOF && ch != '\n' && i < lim)
        line[i++] = ch;
    return i;
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
#include <stdio.h>

#define MAXLENGTH 100

char* trimLeftTrailingSpaces(char a[]);
char* trimRightTrailingSpaces(char a[]);
int getline(char a[], int lim);

int main() {
    char line[MAXLENGTH];
    int count = 0;

    while ((count = getline(line, MAXLENGTH)) > 0) {
        if (line[0] != '\n') {
            trimLeftTrailingSpaces(line);
            trimRightTrailingSpaces(line);
            printf("%s\n", line);
        }
    }

    return 0;
}

char* trimLeftTrailingSpaces(char a[]) {
    int i = 0;
    while (a[i] != '\0' && (a[i] == ' ' || a[i] == '\t' || a[i] == '\n'))
        i++;
    int j = 0;
    while (a[i] != '\0') {
        a[j++] = a[i++];
    }
    a[j] = '\0';
    return a;
}

char* trimRightTrailingSpaces(char a[]) {
    int len = 0;
    for (int i = 0; a[i] != '\0'; i++, len++)
        ;
    
    int i = len - 1;
    while (a[i] == ' ' || a[i] == '\t' || a[i] == '\n')
        i--;
    
    a[i + 1] = '\0';
    return a;
}

int getline(char a[], int lim) {
    char c;
    int i = 0;
    while (i < lim && (c = getchar()) != EOF && c != '\n') {
        a[i++] = c;
    }
    if (c == '\n') {
        a[i++] = c;
        a[i] = '\0';
    } else {
        a[i] = '\0';
    }
    return i;
}
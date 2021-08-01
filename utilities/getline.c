#include <stdio.h>
#include "header.h"

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
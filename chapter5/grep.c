#include <stdio.h>
#include "header.h"

#define MAXLENGTH 100

int main() {
    int count = 0;
    char line[MAXLENGTH];

    while (getline(line, MAXLENGTH) != 0)
        count++;
    printf("%d\n", count);

    return 0;
}
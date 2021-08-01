/* reverse a string */
#include <stdio.h>
#include "utilities.h"

#define MAXLENGTH 100

char* reverse(char a[]);

int main() {
    char line[MAXLENGTH];
    int count = 0;

    while ((count = getLine(line, MAXLENGTH)) > 0) {
        reverse(line);
        printf("%s", line);
    }

    return 0;
}

char* reverse(char a[]) {
    int trail = 0;
    while (a[trail] != '\0')
        trail++;
    trail--;
    if (a[trail] == '\n')
        trail--;
    int head = 0;
    while (head < trail) {
        char tmp = a[head];
        a[head++] = a[trail];
        a[trail--] = tmp;
    }
}
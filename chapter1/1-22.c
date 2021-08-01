#include <stdio.h>
#include "utilities.h"

#define MAXLENGTH 100
#define LIMITS 15

int main() {
    char line[MAXLENGTH];
    int count = 0;
    while ((count = getLine(line, MAXLENGTH)) > 0) {
        printf("%s\n", line);
    }

    return 0;
}

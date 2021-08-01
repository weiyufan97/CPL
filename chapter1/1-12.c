#include <stdio.h>

#define IN 0
#define OUT 1

int main() {
    int state = OUT;

    char c;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            state = OUT;
            putchar('\n');
        } else {
            state = IN;
            putchar(c);
        }
    }
}
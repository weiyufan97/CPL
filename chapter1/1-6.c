#include <stdio.h>

int main() {
    char c;
    while (c = getchar() == EOF) {
        printf("%d ", c);
    }

    return 0;
}
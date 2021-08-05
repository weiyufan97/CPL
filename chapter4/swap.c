/* macro version of swap(t, a, b) */
#include <stdio.h>

#define swap(t, a, b) { \
t tmp = a; a = b; b = tmp; \
}

int main() {
    int a = 1;
    int b = 2;
    printf("%d %d\n", a, b);
    swap(int, a, b);
    printf("%d %d\n", a, b);

    return 0;
}
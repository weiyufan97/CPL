#include <stdio.h>

int main() {
    char ch;
    while ((ch = getchar()) != EOF)
        printf("%d ", ch);
    return 0;
}
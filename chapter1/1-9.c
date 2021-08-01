#include <stdio.h>

int main() {
    char cur, pre = 0;

    while ((cur = getchar()) != EOF) {
        if (cur == ' ' && pre == ' ')
            continue;
        pre = cur;
        putchar(cur);
    }

    return 0;
}
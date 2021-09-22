#include <stdio.h>

int lower(int c) {
    return 'A' <= c && c <= 'Z' ? c - 'A' + 'a' : c;
}

int main() {
    printf("%c %c\n", lower('T'), lower('a'));

    return 0;
}
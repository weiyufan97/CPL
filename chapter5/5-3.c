#include <stdio.h>

void strCat(char* s, char* t);

int main() {
    char s[] = "Hello";
    char t[] = "World";
    strCat(s, t);
    printf("%s\n", s);
}

void strCat(char* s, char* t) {
    while (*s++ != '\0')
        ;
    s--;
    while ((*s++ = *t++) != '\0')
        ;
}
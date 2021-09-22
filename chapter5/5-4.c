#include <stdio.h>
#include <string.h>

int strEnd(char* s, char* t);

int main() {
    char s[] = "HelloWorld";
    char t1[] = "World";
    char t2[] = "ewofjowie";
    printf("%d %d\n", strEnd(s, t1), strEnd(s, t2));

    return 0;
}

int strEnd(char* s, char* t) {
    int ns = strlen(s);
    int nt = strlen(t);
    char* tmp = s;
    while (nt--)
        tmp++;
    while (*tmp++ != '\0')
        s++;
    while (*s++ == *t++)
        if (*s == '\0')
            return 1;
    return 0;
}
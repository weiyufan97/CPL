#include <stdio.h>
#include <string.h>

void strnCpy(char* s, const char* t, size_t n);
void strnCat(char* s, const char* t, size_t n);
int strnCmp(const char* s, const char* t, size_t n);

int main() {
    char s[20];
    strnCpy(s, "HelloWorld", strlen("Hello"));
    printf("%s\n", s);
    strnCat(s, "WorldNiHao", strlen("World"));
    printf("%s\n", s);
    printf("%d %d %d\n", strnCmp(s, "HelloWorld", strlen("HelloWorld")),
                      strnCmp(s, "HelloWorld", strlen("HelloWor")),
                      strnCmp(s, "World", strlen("World")));

    return 0;
}

void strnCpy(char* s, const char* t, size_t n) {
    int i;
    for (i = 0; i < n && *t != '\0'; i++)
        *s++ = *t++;
    *s = '\0';
}

void strnCat(char* s, const char* t, size_t n) {
    int i;
    while (*s++ != '\0')
        ;
    s--;
    for (i = 0; i < n && *t != '\0'; i++)
        *s++ = *t++;
    *s = '\0';
}

int strnCmp(const char* s, const char* t, size_t n) {
    for (int i = 0; i < n && *s == *t; i++, s++, t++) {
        if (*s == '\0')
            return 0;
    }

    return *s - *t;
}
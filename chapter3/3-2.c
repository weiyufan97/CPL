#include <stdio.h>

void escape(char s[], char t[]);

int main() {
    char s[20];
    char t[] = "abc\td\ne\tf\ng";

    escape(s, t);
    printf("%s", s);
}

void escape(char s[], char t[]) {
    int i, j;
    for (i = 0, j = 0; t[i] != '\0'; i++) {
        switch (t[i]) {
        case '\n':
            s[j++] = '\\';
            s[j++] = 'n';
            break;
        case '\t':
            s[j++] = '\\';
            s[j++] = 't';
            break;
        default:
            s[j++] = t[i];
        }
    }
    s[j] = '\0';
}
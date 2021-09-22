#include <stdio.h>

int getch();
void ungetch(int c);
void ungets(char s[]);

int main() {
    char s[] = "Hello";
    ungets(s);
    char c;
    while ((c = getch()) != EOF)
        putchar(c);
    
    return 0;
}

#define BUFLEN 1024

int bufp = 0; // next position to store character
char buf[BUFLEN];

int getch() {
    return bufp == 0 ? getchar() : buf[--bufp];
}

void ungetch(int c) {
    if (bufp >= BUFLEN)
        printf("error: too many characters!\n");
    else
        buf[bufp++] = c;
}

void ungets(char s[]) {
    int n = 0;
    for (int i = 0; s[i] != '\0'; i++, n++)
        ;
    while (n--)
        ungetch(s[n]);
}
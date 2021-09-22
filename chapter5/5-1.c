#include <stdio.h>
#include <ctype.h>

#define BUFLEN 1024

int bufp = 0;
char buf[BUFLEN];

char getch();
void ungetch(char ch);
int getint(int* pn);

int main() {
    int a[3];
    for (int i = 0; i < 3 && getint(&a[i]) != EOF; i++)
        ;
    
    for (int i = 0; i < 3; i++)
        printf("%d ", a[i]);

    return 0;
}

char getch() {
    return bufp == 0 ? getchar() : buf[--bufp];
}

void ungetch(char ch) {
    if (bufp == BUFLEN)
        printf("error: buf is full\n");
    else
        buf[bufp++] = ch;
}

int getint(int* pn) {
    char c;
    int sign;

    while (isspace(c = getch()))
        ;
    
    sign = c == '-' ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    
    if (!isdigit(c)) {
        ungetch(c);
        return c;
    }

    for (*pn = 0; isdigit(c); c = getch())
        *pn = *pn * 10 + c - '0';
    
    if (c != EOF)
        ungetch(c);
    
    return c;
}
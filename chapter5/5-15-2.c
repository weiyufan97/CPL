#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int getint(int* pn);
float getfloat(float* pn);

int main() {
    float a, b;
    getfloat(&a);
    getfloat(&b);

    printf("%.4f\n", a + b);

    return 0;
}

int getint(int* pn) {
    // get next integer from standard input
    char c;
    int sign;

    while (isspace(c = getchar()))
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetc(c, stdin);
        return 0;
    }   

    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getchar();

    if (!isdigit(c)) {
        ungetc(c, stdin);
        return 0;
    }
    
    for (*pn = 0; isdigit(c); c = getchar())
        *pn = *pn * 10 + c - '0';
    *pn *= sign;

    if (c != EOF)
        ungetc(c, stdin);

    return c;
}

float getfloat(float* pn) {
    char ch;
    int sign;
    double power;

    while (isspace(ch = getchar()))
        ;
    
    if (!isdigit(ch) && ch != EOF && ch != '+' && ch != '-' && ch != '.') {
        ungetc(ch, stdin);
        return 0;
    }

    sign = (ch == '-') ? -1 : 1;
    *pn = 0.0;
    // check the first character
    if (ch == '-' || ch == '+')
        ch = getchar();
    
    if (!isdigit(ch) && ch != '.') {
        ungetc(ch, stdin);
        return 0;
    }

    for (; isdigit(ch); ch = getchar())
        *pn = *pn * 10 + ch - '0';
    
    if (ch == '.')
        ch = getchar();
    
    for (power = 1.0; isdigit(ch); ch = getchar(), power *= 10)
        *pn = *pn * 10 + ch - '0';   

    *pn *= sign / power;

    if (ch != EOF && ch != '\n')
        ungetc(ch, stdin);
    
    return ch;
}
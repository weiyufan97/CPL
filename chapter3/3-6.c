#include <stdio.h>

void reverse(char s[]);
void itoa(int n, char s[], int d);

int main() {
    int n = -794543894;
    char s[20];
    int d = 19;

    itoa(n, s, d);
    printf("%s\n", s);
    return 0;
}

void reverse(char s[]) {
    int n;
    for (n = 0; s[n] != '\0'; n++)
        ;
    
    int i, j;
    for (i = 0, j = n - 1; i < j; i++, j--) {
        char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
}

void itoa(int n, char s[], int d) {
    int sign = n < 0 ? -1 : 1;
    int i = 0;
    while (n) {
        int r = n % 10;
        r = r < 0 ? -r : r;
        s[i++] = r + '0';
        n /= 10;
    }
    if (sign < 0)
        s[i++] = '-';
    while (i < d)
        s[i++] = ' ';
    s[i++] = '\0';
    reverse(s);
}
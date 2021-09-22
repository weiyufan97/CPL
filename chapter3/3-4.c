#include <stdio.h>

// -n will overflow when n is -2^(wordsize-1)

void reverse(char s[]);
void itoa(int value, char s[]);

int main() {
    int value = 1 << (sizeof(int) * 8 - 1);
    char s[20];
    itoa(value, s);
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

void itoa(int value, char s[]) {
    int sign = value < 0 ? -1 : 1;
    int i = 0;
    while (value) {
        int r = value % 10;
        r = r < 0 ? -r : r;
        s[i++] = r + '0';
        value /= 10;
    }
    if (sign < 0)
        s[i++] = '-';
    s[i++] = '\0';
    reverse(s);
}
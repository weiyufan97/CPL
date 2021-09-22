#include <stdio.h>

void reverse(char s[]);
void itob(int value, char s[], int b);

int main() {
    int value = 10239;
    int b = 12;
    char s[20];
    itob(value, s, b);

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

void itob(int value, char s[], int b) {
    // '9': 57, 'A': 65
    int sign = value < 0 ? -1 : 1;
    int i = 0;
    while (value) {
        int r = value % b;
        if (r < 10)
            s[i++] = r + '0';
        else
            s[i++] = r - 10 + 'A';
        value /= b;
    }
    if (sign < 0)
        s[i++] = '-';
    reverse(s);
}
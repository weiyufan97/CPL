#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char* argv[]) {
    char c;
    char buf[6];
    int len = strlen(argv[0]);
    for (int i = len - 5, j = 4; i >= len - 9; i--, j--)
        buf[j] = argv[0][i];
    buf[5] = '\0';
    if (strcmp("lower", buf) == 0) {
        while ((c = getchar()) != EOF)
            putchar(tolower(c));
    } else if (strcmp("upper", buf) == 0) {
        while ((c = getchar()) != EOF)
            putchar(toupper(c));
    }

    return 0;
}
#include <stdio.h>

int main() {
    char c;
    int nb = 0;
    int nt = 0;
    int nl = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ')
            nb++;
        else if (c == '\t')
            nt++;
        else if (c == '\n')
            nl++;
    }

    printf("blanks: %d\ntabs: %d\nnewlines: %d\n", nb, nt, nl);

    return 0;
}
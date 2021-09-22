#include <stdio.h>

// return the first location of any character appearing in the s2
int any(char s1[], char s2[]);

int main() {
    char s1[] = "lldml";
    char s2[] = "foeij";

    printf("%d\n", any(s1, s2));
}

int any(char s1[], char s2[]) {
    int i, j;
    for (i = 0; s1[i] != '\0'; i++) {
        for (j = 0; s2[j] != '\0' && s1[i] != s2[j]; j++)
            ;
        if (s2[j] != '\0')
            return i;
    }
    return -1;
}
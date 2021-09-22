#include <stdio.h>

// delete all characters of s1 appearing in s2
void squeeze(char s1[], char s2[]);

int main() {
    char s1[] = "helloworld";
    char s2[] = "erd";

    squeeze(s1, s2);
    printf("%s\n", s1);
}

void squeeze(char s1[], char s2[]) {
    int i, j, k;
    for (i = j = 0; s1[i] != '\0'; i++) {
        for (k = 0; s2[k] != '\0' && s2[k] != s1[i]; k++)
            ;
        if (s2[k] == '\0')
            s1[j++] = s1[i];
    }
    s1[j] = '\0';
}



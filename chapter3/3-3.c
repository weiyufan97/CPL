#include <stdio.h>
#include <ctype.h>
#define MAXINPUT 20
#define MAXLENGTH 200

void expand(char s1[], char s2[]);

int main() {
    char s1[MAXINPUT + 1];
    char s2[MAXLENGTH];

    scanf("%s", s1);
    s1[MAXINPUT] = '\0';
    expand(s1, s2);
    printf("s1: %s\ns2: %s\n", s1, s2);

    return 0;
}

void expand(char s1[], char s2[]) {
    // valid charaters are '-' or digits or alphabets 63
    int i = 0; // to scann s1
    int j = 0; // to construct s2
    int low, high;
    if (!isalnum(s1[i]) && s1[i] != '-') {
        printf("Invalid input: %s\n", s1);
        return;
    }

    for (; s1[i] == '-'; i++)
        ; // skip successive '-'
    // read
    while (s1[i] != '\0') {       
        for (; isalnum(s1[i]); i++, j++)
            s2[j] = s1[i];
        low = s2[j - 1];
        if (s1[i] == '\0')
            break;
        if (s1[i] != '-') {
            printf("Invalid input: %s\n", s1);
            return;
        }

        // expand
        high = s1[i + 1];
        if (isalnum(low) && isalnum(high)) {
            for (int ch = low + 1; ch <= high; ch++, j++)
                s2[j] = ch;
            i += 2;
        }
        else
            i++;
    }
    s2[j] = '\0';
}
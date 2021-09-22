#include <stdio.h>
#define N 4
#define MAXLENGTH 100

char line[MAXLENGTH];

int getline(int maxlength);

int main() {
    int count = 0;
    while ((count = getline(MAXLENGTH)) > 0)
        printf("%s\n", line);

    return 0;
}

int getline(int maxlength) {
    extern char line[]; /* this line could be omitted */
    char ch;
    int i = 0;
    // for (; i < maxlength && (ch = getchar()) != EOF && ch != '\n'; i++)
    //     line[i] = ch;
    for (; (i < maxlength) * ((ch = getchar()) != EOF) * (ch != '\n'); i++)
        line[i] = ch;
    line[i] = '\0';

    return i;
}
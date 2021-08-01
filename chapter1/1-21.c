#include <stdio.h>
#define N 4
#define MAXLENGTH 100

char line[MAXLENGTH];

int getline(int maxlength);

int main() {
    int count = 0;
    while ((count = getline(MAXLENGTH)) > 0) {
        printf("%s\n", line);
    }

    return 0;
}

int getline(int maxlength) {
    extern char line[]; /* this line could be omitted */
    char ch;
    int i = 0;
    while ((ch = getchar()) != EOF && ch != '\n' && i < maxlength) {
        if (ch == '\t') {
            for (int j = 0; j < N; j++, i++) {
                line[i] = ' ';
            }
        }
        else {
            line[i++] = ch;
        }
    }
    line[i] = '\0';

    return i;
}
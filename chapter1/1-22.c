#include <stdio.h>

#define MAXLENGTH 100
#define LIMITS 15

int getline(char a[], int maxlength);

int main() {
    char line[MAXLENGTH];
    int count = 0;
    while ((count = getline(line, MAXLENGTH)) > 0) {
        printf("%s\n", line);
    }

    return 0;
}

int getline(char a[], int maxlength) {
    // return the number of characters of line:
    // positive if getting a line
    // 0 if terminating
    char ch;
    int i = 0;
    int linecount = 0;
    while ((ch = getchar()) != EOF && ch != '\n' && i < maxlength) {
        if (linecount != 0 && linecount % LIMITS == 0) {
            a[i++] = '\n';
        }
        a[i++] = ch;
        linecount++;
    }
    a[i] = '\0';

    return i;
}

/* print all the lines longer than or equal to 80 characters */
#include <stdio.h>

#define MAXLENGTH 200
#define MINLENGTH 80


void copy(char to[], char from[]);

int main() {
    char line[MAXLENGTH];
    int count = 0;

    while ((count = getline(line, MAXLENGTH)) >= 80) {
        printf("%s\n", line);
    }

    return 0;
}



void copy(char to[], char from[]) {
    int i = 0;
    for (; from[i] != '\0'; i++) {
        to[i] = from[i];
    }
    to[i] = '\0';
}
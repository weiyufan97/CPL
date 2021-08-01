#include <stdio.h>
#include <string.h>
#include "header.h"

#define MAXLENGTH 100

int main(int argc, char* argv[]) {
    char line[MAXLENGTH];
    char ch;
    int lineno = 0;
    int number, except, found = 0;

    while (--argc > 0 && (*++argv)[0] == '-') 
        while (ch = *++argv[0])
            switch (ch) {
            case 'x':
                except = 1;
                break;
            case 'n':
                number = 1;
                break;
            default:
                printf("Found illegal option: %c\n", ch);
                argc = 0;
                found = -1;
                break;
            }
    if (argc != 1)
        printf("usage: grep -x -n pattern\n");
    
    while (getLine(line, MAXLENGTH) != 0) {
        lineno++;
        if ((strstr(line, *argv) != NULL) != except) {
            if (number)
                printf("%d: ", lineno);
            printf("%s", line);
            found++;
        }
    }

    return 0;
}
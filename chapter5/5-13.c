#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXLINE 50

char* lineptr[MAXLINE];
int getline(char a[], int lim);
int readlines(char* lineptr[], int lim);
void writelines(char* lineptr[], int nlines, int x);

int main(int argc, char* argv[]) {
    int nline = 0;
    char c;
    int x = 0;

    if (argc != 1 && argc != 2) {
        printf("usage: tail [-n]\n");
        return 0;
    }

    while (--argc && (*++argv)[0] == '-') {
        while ((c = *++argv[0]) != '\0') {
            if (isdigit(c)) {
                x = x * 10 + c - '0';
            }
            else {
                printf("invalid optional parameter: %c\n", c);
                return 0;
            }
        }
    }

    if ((nline = readlines(lineptr, MAXLINE)) >= 0) {
        x = x == 0 ? nline : x;
        writelines(lineptr, nline, x);
    }
    else {
        printf("error\n");
    }
}

int getline(char a[], int lim) {
    // lim is the number of all characters, including '\0'
    char c;
    int i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        a[i++] = c;

    a[i] = '\0';

    return i;
}

int readlines(char* lineptr[], int lim) {
    int len, nlines;
    char* p, line[MAXLINE];

    nlines = 0;
    while ((len = getline(line, MAXLINE)) > 0)
        if (nlines >= lim || (p = calloc(MAXLINE, sizeof(char))) == NULL)
            return -1;
        else {
            line[len] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }

    return nlines;
}

void writelines(char* lineptr[], int nlines, int x) {
    while (nlines--) {
        if (x == nlines) {
            printf("%s\n", lineptr[nlines]);
            x--;
        }
    }
}
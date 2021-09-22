#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 50

char* lineptr[MAXLINES];

int getline(char a[], int lim);
int readlines(char* lineptr[], int lim);
void writelines(char* lineptr[], int nlines);

void qSort(char* lineptr[], int left, int right);

int main() {
    int n;
    if ((n = readlines(lineptr, MAXLINES)) >= 0) {
        qSort(lineptr, 0, n);
        writelines(lineptr, n);
    }
    else {
        printf("error: exceed the max boundary of line nums\n");
    }

    return 0;
}

int getline(char a[], int lim) {
    // lim is the max number of all characters, including '\0'
    char c;
    int i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        a[i++] = c;
    a[i] = '\0';

    return i;
}

#define MAXLEN 1000


int readlines(char* lineptr[], int lim) {
    int len, nlines;
    char* p, line[MAXLEN];

    nlines = 0;
    while ((len = getline(line, MAXLEN)) > 0)
        if (nlines >= lim || (p = calloc(MAXLEN, sizeof(char))) == NULL)
            return -1;
        else {
            line[len] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }

    return nlines;
}

void writelines(char* lineptr[], int nlines) {
    while (nlines--)
        printf("%s\n", *lineptr++);
}

void qSort(char* lineptr[], int left, int right) {
    // [left, right)
    // return when the number of elements is less than 2
    if (right - left < 2)
        return;
    void swap(char* lineptr[], int i, int j);
    // swap the first and the middle to improve efficiency
    swap(lineptr, left, (left + right) >> 1);
    int last = left; // the left bound of the less sequence

    for (int i = left + 1; i < right; i++) {
        // i: the next position to be scanned
        if (strcmp(lineptr[i], lineptr[left]) < 0)
            swap(lineptr, i, ++last);
    }

    swap(lineptr, left, last);
    qSort(lineptr, left, last);
    qSort(lineptr, last + 1, right);
}

void swap(char* lineptr[], int i, int j) {
    char* tmp = lineptr[i];
    lineptr[i] = lineptr[j];
    lineptr[j] = tmp;
}
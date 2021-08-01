/* reverse a string */
#include <stdio.h>

#define MAXLENGTH 100

int getline(char a[], int lim);
char* reverse(char a[]);

int main() {
    char line[MAXLENGTH];
    int count = 0;

    while ((count = getline(line, MAXLENGTH)) > 0) {
        reverse(line);
        printf("%s", line);
    }

    return 0;
}

int getline(char a[], int lim) {
    char c;
    int i = 0;
    while (i < lim && (c = getchar()) != EOF && c != '\n') {
        a[i++] = c;
    }
    if (c == '\n') {
        a[i++] = c;
        a[i] = '\0';
    } else {
        a[i] = '\0';
    }
    return i;
}

char* reverse(char a[]) {
    int trail = 0;
    while (a[trail] != '\0')
        trail++;
    trail--;
    if (a[trail] == '\n')
        trail--;
    int head = 0;
    while (head < trail) {
        char tmp = a[head];
        a[head++] = a[trail];
        a[trail--] = tmp;
    }
}
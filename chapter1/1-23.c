#include <stdio.h>

#define MAXLENGTH 300

int readFile(char c[], int maxlength);
void eliminateComments(char a[]);

int main() {
    char content[MAXLENGTH];
    int count = 0;

    count = readFile(content, MAXLENGTH);
    printf("Original:\n%s\n", content);
    eliminateComments(content);
    printf("Subsequent:\n%s\n", content);

    return 0;
}

int readFile(char a[], int maxlength) {
    int i = 0;
    char ch;
    while ((ch = getchar()) != EOF && i < maxlength) {
        a[i++] = ch;
    }

    if (i == maxlength) {
        a[i - 1] = '\0';
    }
    else {
        a[i] = '\0';
    }

    return i; 
}

void eliminateComments(char a[]) {
    int i = 0; // next position to scan
    int j = -1; // end of text

    while (a[i] != '\0') {
        if (a[i] == '/' && a[i + 1] == '/') {
            for (; a[i] != '\n'; i++)
                ;
            i++;
        }
        a[++j] = a[i++];
    }

    a[++j] = '\0';
}
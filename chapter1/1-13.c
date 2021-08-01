/* count the length of different word(1-20) */
#include <stdio.h>

#define IN 0
#define OUT 1
#define MAXLENGTH 10

int main() {
    char c;
    int len = 0;
    int nLength[MAXLENGTH];
    int state = IN;

    for (int i = 0; i < MAXLENGTH; i++)
        nLength[i] = 0;
    
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            state = OUT;
            if (len <= MAXLENGTH && 1 <= len)
                nLength[len]++;
            len = 0;
        }
        else if (state == IN) {
            len++;
        } else {
            state = IN;
        }
    }

    // print the histogram
    // horizontal
    // for (int i = 0; i < MAXLENGTH; i++) {
    //     printf("Number of length%d: %d\n", i + 1, nLength[i]);
    // }

    // vertical
    printf("Length:\t\t");
    for (int i = 0; i < MAXLENGTH; i++) {
        printf("%10d", i + 1);
    }
    printf("\n");
    printf("Number:\t\t");
    for (int i = 0; i < MAXLENGTH; i++) {
        printf("%10d", nLength[i]);
    }

    return 0;
}

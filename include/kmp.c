#include <stdio.h>
#include <stdlib.h>

static int* helper(char pattern[]) {
    int len = 0;
    for (int i = 0; pattern[i] != '\0'; i++, len++)
        ;
    int* pi = (int*)(malloc(len * sizeof(int)));
    pi[0] = 0; // for the case that only one character, the longest prefix length is 0

    int k = 0; // number of matched characters
    for (int i = 1; pattern[i] != '\0'; i++) { /* forward in the loop */
        while (k > 0 && pattern[k] != pattern[i]) /* check the next character */
            k = pi[k - 1]; // backward here
        // now k is either positive or zero
        if (pattern[k] == pattern[i])
            k++; // length of the longest prefix increses
        pi[i] = k; // store the result
    }

    return pi;
}

int kmp(char text[], char pattern[]) {
    int* pi = helper(pattern);
    int k = 0; // number of matched characters

    for (int i = 0; text[i] != '\0'; i++) {
        while (k > 0 && pattern[k] != text[i])
            k = pi[k - 1];
        if (pattern[k] == text[i])
            k++;
        if (pattern[k] == '\0')
            return i; // match the whole pattern
    }
}

int main() {
    char text[100];
    char pattern[10];

    scanf("%s %s", text, pattern);
    int idx = kmp(text, pattern);

    printf("%d\n", idx);

    return 0;    
}
#include <stdio.h>

#define isupper(c) (65 <= (c)) && ((c) <= 90)

int main() {
    if (isupper('A'))
        printf("A\n");
    if (isupper('Z'))
        printf("Z\n");
    return 0;
}
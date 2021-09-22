/* recursive version of itoa: integer to string */
#include <stdio.h>
#include <stdlib.h>

char* itoa(int n) {
    static char res[20];
    static char* tmp = res;
    
    if (n / 10) {
        itoa(n / 10);
    }
    *tmp++ = (n % 10) + '0';
    
    return tmp;
}

int main() {
    char* s = itoa(474432);
    printf("%s\n", s);

    return 0;
}
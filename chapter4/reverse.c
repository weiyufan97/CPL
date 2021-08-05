/* recursive version of reverse */
#include <stdio.h>
#include <string.h>

char* reverse(const char* str) {
    static char res[20];
    static char* tmp = res;

    if (*str != '\0') {
        reverse(str + 1);
        *tmp++ = *str;
    }
    
    return res;
}

int main() {
    const char* str = "hello world s";
    char* res = reverse(str);
    if (res != NULL);
        printf("%s\n", res);

    return 0;
}
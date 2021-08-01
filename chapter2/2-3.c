/* htoi */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int htoi(const char* str);
int helper(char ch) {
    return ch == 'a' || ch == 'A' ||
           ch == 'b' || ch == 'B' ||
           ch == 'c' || ch == 'C' ||
           ch == 'd' || ch == 'D' ||
           ch == 'e' || ch == 'E' ||
           ch == 'f' || ch == 'F';
}

int main() {
    char buf[100];

    printf("input a hexical number:");
    scanf("%s", buf);

    printf("in decimal form:%d", htoi(buf));
    return 0;
}

int htoi(const char* str) {
    int i;
    int res = 0;
    if (str[0] == '0') {
        if (str[1] == 'x' || str[1] == 'X')
            i = 2;
        else
            exit(EXIT_FAILURE);
    }
    else 
        i = 0;

    while (str[i] != '\0') {
        if (isdigit(str[i]))
            res = res * 16 + str[i] - '0';
        else if (helper(str[i]))
            res = res * 16 + str[i] - 'a' + 10;
        else
            exit(EXIT_FAILURE);
        i++;
    }
    
    return res;
}
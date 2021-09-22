#include <stdio.h>
#include <ctype.h>

double atof(char s[]);

int main() {
    char s[] = "-12.345e2";
    printf("%f\n", atof(s));

    return 0;
}

double atof(char s[]) {
    // skip the white spaces
    int i = 0;
    while (isspace(s[i]))
        i++;
    // test if valid: + - digit .
    if (s[i] != '+' && s[i] != '-' && s[i] != '.' && !isdigit(s[i])) {
        printf("invalid input: %s\n", s);
        return 0.0;
    }

    int sign; // sign of the result: pos or neg
    int ssign; // scientifix sign: multiply or divide
    int power = 1.0;
    int spart = 0; // scientific part
    double spower = 1.0;
    double res = 0.0;
    sign = (s[i] == '-') ? -1 : 1;

    if (s[i] == '+' || s[i] == '-')
        i++;
    
    // test
    if (!isdigit(s[i]) && s[i] != '.') {
        printf("invalid input: %s\n", s);
        return 0.0;
    }
    // read left part, if a[i] is '.' this part will pass
    for (; isdigit(s[i]); i++)
        res = res * 10 + s[i] - '0';

    if (s[i] == '.')
        i++;
    // read right part, if a[i] is 'e' or 'E' or '\0' this part will pass
    for (; isdigit(s[i]); i++, power *= 10)
        res = res * 10 + s[i] - '0';
    
    // test scientifix notation
    if (s[i] == 'e' || s[i] == 'E')
        i++;
    ssign = (s[i] == '-') ? -1 : 1;

    if (s[i] == '+' || s[i] == '-')
        i++;
    
    for (; isdigit(s[i]); i++)
        spart = spart * 10 + s[i] - '0';
    for (int j = 1; j <= spart; j++)
        spower *= 10;
    if (ssign == 1)
        res = res / power * spower;
    else
        res = res / power / spower;
    res *= sign;
    
    return res;
}
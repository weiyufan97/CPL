/* atof: string to double handling the scientific notation */
#include <stdio.h>
#include <ctype.h>

double atof(const char* a);

int main() {
    const char* str = "78912.345e-6";

    printf("%.12f\n", atof(str));
    return 0;
}

double atof(const char* a) {
    // skip the white spaces
    int i = 0;
    while (isspace(a[i]))
        i++;
    // test if valid: + - digit .
    if (a[i] != '+' && a[i] != '-' && a[i] != '.' && !isdigit(a[i])) {
        printf("invalid input: %s\n", a);
        return 0.0;
    }

    int sign; // sign of the result: pos or neg
    int ssign; // scientifix sign: multiply or divide
    int power = 1.0;
    int spart = 0; // scientific part
    double spower = 1.0;
    double res = 0.0;
    sign = (a[i] == '-') ? -1 : 1;

    if (a[i] == '+' || a[i] == '-')
        i++;
    
    // test
    if (!isdigit(a[i]) && a[i] != '.') {
        printf("invalid input: %s\n", a);
        return 0.0;
    }
    // read left part, if a[i] is '.' this part will pass
    for (; isdigit(a[i]); i++)
        res = res * 10 + a[i] - '0';

    if (a[i] == '.')
        i++;
    // read right part, if a[i] is 'e' or 'E' or '\0' this part will pass
    for (; isdigit(a[i]); i++, power *= 10)
        res = res * 10 + a[i] - '0';
    
    // test scientifix notation
    if (a[i] == 'e' || a[i] == 'E')
        i++;
    ssign = (a[i] == '-') ? -1 : 1;

    if (a[i] == '+' || a[i] == '-')
        i++;
    
    for (; isdigit(a[i]); i++)
        spart = spart * 10 + a[i] - '0';
    for (int j = 1; j <= spart; j++)
        spower *= 10;
    if (ssign == 1)
        res = res / power * spower;
    else
        res = res / power / spower;
    res *= sign;
    
    return res;
}


#include <stdio.h>

double c2f(double celcius) {
    return 32 + 1.8 * celcius;
}

double f2c(double fahrenheit) {
    return (fahrenheit - 32) / 1.8;
}

int main() {
    double c = 36.7;
    printf("%-20s%-20s\n", "Celcius", "Fahrenheit");
    printf("%-20.4f%-20.4f\n", c, c2f(c));

    double f = 100.12;
    printf("%-20s%-20s\n", "Fahrenheit", "Celcius");
    printf("%-20.4f%-20.4f\n", f, f2c(f));

    return 0;
}
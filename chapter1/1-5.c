#include <stdio.h>

int main() {
    double fahr, celcius;
    int lower = 0, upper = 300, step = 20;
    celcius = upper;

    printf("%s %s\n", "celcius", "fahr");
    while (celcius >= lower) {
        fahr = (celcius + 32.0) * (9.0 / 5.0);
        printf("%6.1f %3.0f\n", celcius, fahr);
        celcius -= step;
    }

    return 0;
}
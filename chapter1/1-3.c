#include <stdio.h>

int main() {
    double fahr, celcius;
    int lower = 0, upper = 360, step = 20;

    fahr = lower;
    printf("%s %s\n", "fahr", "celcius");
    while (fahr <= upper) {
        celcius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f %6.1f\n", fahr, celcius);
        fahr += step;
    }

    return 0;
}
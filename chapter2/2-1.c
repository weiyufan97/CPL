#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    printf("char: %d - %d\n", CHAR_MIN, CHAR_MAX);
    printf("unsigned char: %u - %u\n", 0, UCHAR_MAX);

    printf("short: %d - %d\n", SHRT_MIN, SHRT_MAX);
    printf("unsigned short: %u - %u\n", 0, USHRT_MAX);

    printf("int: %d - %d\n", INT_MIN, INT_MAX);
    printf("unsigned int: %u - %u\n", 0, INT_MAX);

    printf("long: %ld - %ld\n", LONG_MIN, LONG_MAX);
    printf("unsigned long: %lu - %lu\n", 0, ULONG_MAX);

    printf("long long: %lld - %lld\n", LLONG_MIN, LLONG_MAX);
    printf("unsigned long long: %llu - %llu\n", 0, ULLONG_MAX);

    char cmin = 1 << (sizeof(char) * 8 - 1);
    char cmax = ~cmin;
    printf("char: %d - %d\n", cmin, cmax);
    printf("unsigned char: %u - %u\n", 0, 0xFF);

    short shrt_min = 1 << (sizeof(short) * 8 - 1);
    short shrt_max = ~shrt_min;
    printf("short: %d - %d\n", shrt_min, shrt_max);
    printf("unsigned short: %u - %u\n", 0, 0xFFFF);

    int int_min = 1 << (sizeof(int) * 8 - 1);
    int int_max = ~int_min;
    printf("int: %d - %d\n", int_min, int_max);
    printf("unsigned int: %u - %u\n", 0, 0xFFFFFFFF);
    
    int long_min = 1 << (sizeof(long) * 8 - 1);
    int long_max = ~long_min;
    printf("long: %d - %d\n", long_min, long_max);
    printf("unsigned long: %lu - %lu\n", 0, 0xFFFFFFFF);

    long long llong_min = 1ll << (sizeof(long long) * 8 - 1);
    long long llong_max = ~llong_min;
    printf("long long: %lld - %lld\n", llong_min, llong_max);
    printf("unsigned long long: %llu - %llu\n", 0, 0xFFFFFFFFFFFFFFFF);

    // for floating number:
    // the maximum absolute value is when:
    // the exponent field is all ones minus one, i.e. for 32-bit:
    // it is 11111110
    // the fraction field is all ones
    // note: Bias == 2^(k-1) - 1. Thus for 32-bit it is 127 for 64-bit it is 1023

    printf("positive float: %g - %g\n", (float)FLT_MIN, (float)FLT_MAX);
    printf("negtive float: %g - %g\n", (float)-FLT_MAX, (float)-FLT_MIN);

    printf("positive double: %g - %g\n", (double)DBL_MIN, (double)DBL_MAX);

}
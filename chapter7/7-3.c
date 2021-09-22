#include <stdio.h>
#include <stdarg.h>

void minprintf(char* fmt, ...);

int main() {
    minprintf("%d %f %s %x %u", 1, 2.3, "hello", 34, 123);

    return 0;
}

void minprintf(char* fmt, ...) {
    int ival;
    unsigned uival;
    double dval;
    char* p, * sval;

    va_list ap;
    va_start(ap, fmt);

    for (p = fmt; *p != '\0'; p++) {
        if (*p != '%') {
            putchar(*p);
            continue;
        }
        switch (*++p) {
        case 'd':
            ival = va_arg(ap, int);
            printf("%d", ival);
            break;
        case 'x':
            ival = va_arg(ap, int);
            printf("%x", ival);
            break;
        case 'u':
            uival = va_arg(ap, unsigned);
            printf("%u", uival);
            break;
        case 'f':
            dval = va_arg(ap, double);
            printf("%f", dval);
            break;
        case 's':
            for (sval = va_arg(ap, char*); *sval != '\0'; sval++)
                putchar(*sval);
            break;
        default:
            putchar(*p);
            break;
        }
    }

    va_end(ap);
}
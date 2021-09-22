#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>

void minscanf(char* fmt, ...);

int main() {
    int x;
    float y;
    char buf[10];

    minscanf("%d %f %s", &x, &y, buf);
    printf("%d %f %s", x, y, buf);

    return 0;
}

void minscanf(char* fmt, ...) {
    va_list ap;
    int* ip;
    double* dp;
    char* p, * sp;
    va_start(ap, fmt);

    for (p = fmt; *p != '\0'; p++) {
        if (*p != '%')
            continue;
        switch (*++p) {
        case 'd':
            ip = va_arg(ap, int*);
            scanf("%d", ip);
            break;
        case 'f':
            dp = va_arg(ap, double*);
            scanf("%f", dp);
            break;
        case 's':
            sp = va_arg(ap, char*);
            scanf("%s", sp);
            break;
        default:
            break;
        }
    }

    va_end(ap);
}
#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

int day_of_year(int year, int month, int day);
void month_day(int year, int day, int* m, int* d);

int main() {
    printf("%d\n", day_of_year(1998, 4, 20));
    int month, day;
    month_day(1998, 110, &month, &day);
    printf("%d %d\n", month, day);

    return 0;
}

int day_of_year(int year, int month, int day) {
    if (month < 1 || month > 12) {
        printf("error: invalid month: %d\n", month);
        return -1;
    }

    int i, leap;
    leap = year % 4 == 0 || year % 100 != 0 && year && 400 == 0;

    if (day < 0 || day > daytab[leap][month]) {
        printf("error: invalid day: %d\n", day);
        return -1;
    }

    for (i = 1; i < month; i++)
        day += daytab[leap][i];
    return day;
}

void month_day(int year, int day, int* m, int* d) {
    int i, leap;
    leap = year % 4 == 0 || year % 100 != 0 && year && 400 == 0;

    if (day < 0 || day > 365 + leap) {
        printf("error: invalid day: %d\n", day);
        return;
    }

    for (i = 1; day > daytab[leap][i]; i++)
        day -= daytab[leap][i];
    
    *m = i;
    *d = day;
}
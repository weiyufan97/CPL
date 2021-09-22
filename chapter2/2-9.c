#include <stdio.h>

/*
    for x: ddddd...1000...0000
    x - 1 is: ddddd...0111...111
    x & (x - 1) is ddddd...
    striping the last '1'
*/

int bitcount(unsigned x);

int main() {
    unsigned x = 0xFFFFEEEE;
    printf("%d\n", bitcount(x));
}

int bitcount(unsigned x) {
    int n = 0;
    while (x) {
        x &= x - 1;
        n++;
    }
    return n;
}
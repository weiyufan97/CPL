#include <stdio.h>

int binsearch(int x, int arr[], int n);

int main() {
    int arr[10] = {1, 9, 10, 28, 34, 56, 65, 68, 71, 89};

    printf("%d %d\n", binsearch(9, arr, 10), binsearch(57, arr, 10));
    return 0;
}

int binsearch(int x, int arr[], int n) {
    int lo = 0, hi = n; // [lo, hi)
    while (1 < hi - lo) {
        // at least two elements
        int mi = (lo + hi) >> 1;
        if (x < arr[mi]) // left branch
            hi = mi;
        else // right branch
            lo = mi;
    }

    return x == arr[lo] ? lo : -1;
}
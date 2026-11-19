// -----------------------------------------------------------------------------
// 03_restrict.c - a promise that this pointer is the only way in
//
// Run:  scripts/run.sh 08-qualifiers-and-alignment/03_restrict.c
// -----------------------------------------------------------------------------
//
// restrict qualifies a pointer. On a function parameter, it is a promise
// by the caller: for the duration of the call, every access to the object
// that pointer points at goes through that pointer (or a pointer derived
// from it), and not through another argument or a global.
//
// The promise lets the compiler keep a loaded value in a register instead
// of reloading it before every use, because nothing else in the call can
// have written it. memcpy has restrict on both pointers. memmove does not,
// and memmove is the one you call when the regions may overlap.
//
// Breaking the promise is undefined behaviour. This program does not break
// it: a and b are two arrays. Passing the same array as both arguments
// would be a broken promise, and the function would be entitled to return
// anything, or not return.
//
// restrict on a local pointer means the same promise for the lifetime of
// that pointer. It is rare outside parameters. The type of the pointer
// includes the qualifier, the way const does.

#include <stdio.h>

int dot(int n, const int *restrict a, const int *restrict b) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i] * b[i];
    }
    return sum;
}

int main(void) {
    int left[] = {1, 2, 3};
    int right[] = {4, 5, 6};
    printf("%d\n", dot(3, left, right));
    return 0;
}

// Output:
// 32

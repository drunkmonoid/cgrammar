// -----------------------------------------------------------------------------
// 04_limits.c - the ranges <limits.h> promises, and the widths C23 names
//
// Run:  scripts/run.sh 04-integer-types/04_limits.c
// -----------------------------------------------------------------------------
//
// <limits.h> gives the minimum and maximum of every standard integer type,
// as macros that are integer constant expressions. INT_MAX is the largest
// int. INT_MIN is the most negative, and in C23 it is exactly -INT_MAX - 1,
// because signed integers are two's complement (file 07).
//
// C23 adds a _WIDTH macro for each type: the number of bits used to
// represent values, not counting padding. There is no padding on this
// platform, so INT_WIDTH equals CHAR_BIT * sizeof(int). BOOL_WIDTH is 1
// even though sizeof(bool) is 1 byte: seven of those bits are padding.
//
// The numbers below are x86-64 Linux. A 32-bit platform has LONG_WIDTH 32.
// Code that must accept either asks for the width or uses a type from
// <stdint.h> instead of assuming it.

#include <limits.h>
#include <stdio.h>

int main(void) {
    printf("%d %d %d %d\n", CHAR_BIT, CHAR_WIDTH, BOOL_WIDTH, USHRT_WIDTH);
    printf("%d %d %d\n", INT_WIDTH, LONG_WIDTH, LLONG_WIDTH);
    printf("%d\n", INT_WIDTH == CHAR_BIT * (int)sizeof(int));

    printf("%d %d\n", INT_MAX, INT_MIN);
    printf("%d\n", INT_MIN == -INT_MAX - 1);
    printf("%u\n", UINT_MAX);
    return 0;
}

// Output:
// 8 8 1 16
// 32 64 64
// 1
// 2147483647 -2147483648
// 1
// 4294967295

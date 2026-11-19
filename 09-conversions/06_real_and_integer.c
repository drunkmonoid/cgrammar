// -----------------------------------------------------------------------------
// 06_real_and_integer.c - between a floating value and an integer
//
// Run:  scripts/run.sh 09-conversions/06_real_and_integer.c
// -----------------------------------------------------------------------------
//
// A real value converted to an integer is truncated toward zero. 2.9
// becomes 2. -2.9 becomes -2. It does not round to nearest. The fractional
// part is discarded, and there is no diagnostic.
//
// If the value does not fit in the integer type, the behaviour is
// undefined. A floating value past INT_MAX is not a clever way to write
// INT_MAX.
//
// The other direction is defined and may round. Not every int is an exact
// float: a float has 24 bits of significand, and 16777217 is 2^24 + 1.
// The conversion produces 16777216. The integer is not preserved, and the
// comparison against the original is false. double has 53 bits, which is
// enough for every 32-bit int and not enough for every 64-bit long.
//
// The value is read through a volatile object so it is not a constant
// expression. A conversion of a constant that changes the value is a
// diagnostic on its own, which would hide the runtime rule.

#include <stdio.h>

int main(void) {
    printf("%d %d %d\n", (int)2.9, (int)-2.9, (int)2.1f);

    volatile int big = 16777217;
    printf("%d\n", (int)(float)big);
    printf("%d\n", (int)(float)big == big);

    int n = 3;
    printf("%.1f\n", (double)n);
    return 0;
}

// Output:
// 2 -2 2
// 16777216
// 0
// 3.0

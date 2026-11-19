// -----------------------------------------------------------------------------
// 01_real_types.c - float, double, and long double
//
// Run:  scripts/run.sh 05-floating-types/01_real_types.c
// -----------------------------------------------------------------------------
//
// Three real floating types. float is the narrowest, then double, then
// long double, which is at least as wide as double. A floating constant
// with no suffix has type double (chapter 3); the variables below use the
// suffixes so each object has the type it looks like.
//
// On x86-64 Linux:
//
//     float        4 bytes, 24 bits of significand (IEEE binary32)
//     double       8 bytes, 53 bits of significand (IEEE binary64)
//     long double  16 bytes, 64 bits of significand
//
// That long double is the x87 extended format, stored in 16 bytes. It is
// not IEEE binary128, which would have 113 significand bits. sizeof does
// not tell you the precision; LDBL_MANT_DIG does.
//
// Most decimal fractions are not exact in binary. Ten copies of 0.1 do not
// add up to 1. That is not a bug in the addition; 0.1 is not the value
// that was stored. A hexadecimal float writes the value that is stored.

#include <float.h>
#include <stdio.h>

int main(void) {
    printf("%zu %zu %zu\n", sizeof(float), sizeof(double), sizeof(long double));
    printf("%d %d %d\n", FLT_MANT_DIG, DBL_MANT_DIG, LDBL_MANT_DIG);

    double tenth = 0.1;
    double sum = 0.0;
    for (int i = 0; i < 10; i++) {
        sum += tenth;
    }
    printf("%d\n", sum == 1.0);
    printf("%d\n", 0x1p-1 == 0.5);
    return 0;
}

// Output:
// 4 8 16
// 24 53 64
// 0
// 1

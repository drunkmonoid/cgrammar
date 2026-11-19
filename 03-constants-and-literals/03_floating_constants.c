// -----------------------------------------------------------------------------
// 03_floating_constants.c - decimal and hexadecimal floating constants
//
// Run:  scripts/run.sh 03-constants-and-literals/03_floating_constants.c
// -----------------------------------------------------------------------------
//
// A floating constant has a significand and, optionally, an exponent. With
// no suffix its type is double. f or F makes it float. l or L makes it
// long double.
//
//     1.5      1.5e1      1e-3      .5      1.
//
// A digit on one side of the point is enough. Digit separators work here
// too, in the significand and in the exponent.
//
// A hexadecimal floating constant spells the significand in hex and the
// exponent in decimal as a power of two, with p (not e) separating them:
//
//     0x1.8p1   is  1.5 × 2^1  = 3
//     0x1p-1    is  1   × 2^-1 = 0.5
//     0x10p0    is  16  × 2^0  = 16
//
// The hex form is exact for binary fractions. 0.1 is not a binary fraction,
// so the decimal spelling 0.1 is already an approximation; 0x1.999999999999ap-4
// is the double you actually get. Hex floats are the way to write a binary
// value and mean it.
//
// Decimal floating suffixes (df, dd, dl) belong to the decimal types in
// chapter 5. They are not suffixes of float, double, or long double.

#include <stdio.h>

int main(void) {
    printf("%zu %zu %zu\n", sizeof(1.0f), sizeof(1.0), sizeof(1.0L));
    printf("%zu %zu\n", sizeof(0x1p0f), sizeof(0x1p0L));

    printf("%.1f\n", 1.5e1);
    printf("%.2f\n", 1'000.25);

    printf("%.1f %.1f %.1f\n", 0x1.8p1, 0x1p-1, 0x10p0);

    // 0x1p-2 is the value one quarter, written so the rounding is visible
    // only in how we print it.
    printf("%.2f\n", 0x1p-2);
    return 0;
}

// Output:
// 4 8 16
// 4 16
// 15.0
// 1000.25
// 3.0 0.5 16.0
// 0.25

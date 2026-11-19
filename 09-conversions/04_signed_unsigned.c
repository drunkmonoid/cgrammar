// -----------------------------------------------------------------------------
// 04_signed_unsigned.c - a negative value, converted because the other operand is unsigned
//
// Run:  scripts/run.sh 09-conversions/04_signed_unsigned.c
// -----------------------------------------------------------------------------
//
// When a signed operand and an unsigned operand meet, and the signed type
// cannot hold every unsigned value, the signed value is converted to the
// unsigned type. For a negative value that conversion is modular. The
// 32-bit int -1 becomes the unsigned int 4294967295.
//
// The comparisons below are written with a cast so the conversion is the
// one the source asks for. The same comparison without a cast is the next
// file: it is well-defined, it is almost never what was meant, and both
// compilers warn about it.
//
// The addition is the same conversion, after the usual promotions. A
// signed char of -1 promotes to the int -1, then the addition with an
// unsigned int converts that -1, and -1 converted plus 1 is 0. The result
// is not -1 + 1 computed in int. The unsigned operand decided the type.

#include <stdio.h>

int main(void) {
    int i = -1;
    unsigned u = 1;

    printf("%d\n", (unsigned)i > u);
    printf("%d\n", i < (int)u);

    signed char sc = -1;
    printf("%u\n", sc + u);
    return 0;
}

// Output:
// 1
// 1
// 0

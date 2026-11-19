// -----------------------------------------------------------------------------
// 02_float_h.c - what <float.h> reports about the three types
//
// Run:  scripts/run.sh 05-floating-types/02_float_h.c
// -----------------------------------------------------------------------------
//
// <float.h> is the floating counterpart of <limits.h>. The macros are
// integer or floating constant expressions.
//
//     FLT_RADIX        the base of the exponent. 2 on any IEC 60559 machine.
//     FLT_MANT_DIG     significand bits, including the implicit leading 1
//     FLT_DIG          how many decimal digits survive a round trip
//                      through this type
//     FLT_EPSILON      the difference between 1 and the next larger value
//     FLT_ROUNDS       the current rounding direction. 1 is to nearest.
//
// DBL_ and LDBL_ name the same properties of the wider types.
//
// FLT_EPSILON of a binary32 float is 2^-23. Comparing against a hexadecimal
// float checks the value without printing a decimal approximation.
//
// __STDC_IEC_60559_BFP__ is defined to 201404L when the implementation
// conforms to Annex F, the binding to IEEE 754 / IEC 60559 binary formats.
// This toolchain defines it. The older name __STDC_IEC_559__ means the same
// thing and is kept for existing code.

#include <float.h>
#include <stdio.h>

int main(void) {
    printf("%d %d %d\n", FLT_RADIX, FLT_DIG, DBL_DIG);
    printf("%d %d\n", FLT_EVAL_METHOD, FLT_ROUNDS);
    printf("%d %d\n", FLT_EPSILON == 0x1p-23f, DBL_EPSILON == 0x1p-52);
    printf("%ld\n", (long)__STDC_IEC_60559_BFP__);
    return 0;
}

// Output:
// 2 6 15
// 0 1
// 1 1
// 201404

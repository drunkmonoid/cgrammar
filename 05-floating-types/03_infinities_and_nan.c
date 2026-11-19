// -----------------------------------------------------------------------------
// 03_infinities_and_nan.c - values that are not numbers, on purpose
//
// Run:  scripts/run.sh 05-floating-types/03_infinities_and_nan.c
// -----------------------------------------------------------------------------
//
// IEC 60559 arithmetic has values outside the real numbers.
//
//     INFINITY   a result that overflowed, or 1 divided by zero
//     NAN        a result that has no numeric meaning, such as 0/0
//                or the square root of a negative number
//
// Infinities are signed. 1.0/0.0 is +infinity; -1.0/0.0 is -infinity.
// Dividing by zero is defined for floating types. It is undefined for
// integers, which have no infinity to return.
//
// A NaN compares unequal to everything, including itself. That is the
// portable test: x != x. isnan, from <math.h>, says the same thing.
// isinf is true for both infinities. signbit reads the sign even of zero,
// so -0.0 is distinct from 0.0 as a sign and equal to it as a value.
//
// isinf returns a nonzero value, not necessarily 1. Compare it with zero.
//
// These macros and functions require Annex F. The previous file checked
// that this toolchain provides it.

#include <math.h>
#include <stdio.h>

int main(void) {
    printf("%d %d %d\n",
           isinf(INFINITY) != 0, isinf(-INFINITY) != 0, isnan(NAN) != 0);
    printf("%d\n", NAN == NAN);
    printf("%d %d\n", signbit(-0.0) != 0, signbit(0.0) != 0);
    printf("%g\n", 1.0 / INFINITY);
    printf("%d\n", -0.0 == 0.0);
    return 0;
}

// Output:
// 1 1 1
// 0
// 1 0
// 0
// 1

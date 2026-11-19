// -----------------------------------------------------------------------------
// 04_shifts.c - multiplication and division by a power of two, when they are defined
//
// Run:  scripts/run.sh 10-expressions/04_shifts.c
// -----------------------------------------------------------------------------
//
// E1 << E2 shifts the value of E1 left by E2 bit positions, which multiplies
// it by 2^E2 when the result can be represented in the result type.
// E1 >> E2 shifts right. For a nonnegative E1 that divides by 2^E2,
// discarding the fraction.
//
// The right operand must be at least zero and strictly less than the width
// of the promoted left operand. 1 << 32 is undefined for a 32-bit int.
// So is a negative shift count. The compiler is not required to diagnose
// either.
//
// A left shift whose result cannot be represented is undefined. 1 << 31
// does not fit in a signed 32-bit int, because 2^31 is one past INT_MAX.
// The unsigned shift 1u << 31 is defined, and the result is 2^31.
//
// A right shift of a negative value is implementation-defined. On x86-64,
// gcc and clang both sign-extend, so -8 >> 1 is -4. That is the recorded
// result. It is not a promise of the language. A value you need to shift
// as bits should be unsigned, where the shift is defined to fill with
// zeroes.

#include <stdio.h>

int main(void) {
    printf("%d\n", 1 << 4);
    printf("%u\n", 1u << 31);
    printf("%u\n", 0xFFu >> 3);
    printf("%d\n", (-8) >> 1);
    return 0;
}

// Output:
// 16
// 2147483648
// 31
// -4

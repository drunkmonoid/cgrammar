// -----------------------------------------------------------------------------
// 07_twos_complement.c - the only representation C23 allows
//
// Run:  scripts/run.sh 04-integer-types/07_twos_complement.c
// -----------------------------------------------------------------------------
//
// Until C23 an implementation could represent signed integers in two's
// complement, ones' complement, or sign and magnitude. C23 requires two's
// complement. The consequences that programs may now rely on:
//
//   - There is one value that cannot be negated: the most negative one.
//     INT_MIN is -INT_MAX - 1, not -INT_MAX. Negating INT_MIN is undefined.
//   - -1 has every value bit set. Converting it to unsigned int yields
//     UINT_MAX, and ~0, which flips every bit of the int 0, is -1.
//   - A conversion from unsigned to signed that does not fit reinterprets
//     the bits. It does not trap, and it is not undefined.
//
// The bit patterns are part of the language now. The widths are not:
// nothing here says that int has 32 bits, only that whatever bits it has
// are a two's-complement value.

#include <limits.h>
#include <stdio.h>

int main(void) {
    printf("%d\n", INT_MIN == -INT_MAX - 1);
    printf("%d\n", ~0);

    int minus_one = -1;
    printf("%u\n", (unsigned)minus_one);

    // 2^31 does not fit in a 32-bit int. The conversion is defined, and
    // the bit pattern 0x80000000 is INT_MIN.
    unsigned high = 0x80000000u;
    printf("%d\n", (int)high == INT_MIN);
    return 0;
}

// Output:
// 1
// -1
// 4294967295
// 1

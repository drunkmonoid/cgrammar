// -----------------------------------------------------------------------------
// 08_unsigned_wrap.c - unsigned arithmetic is modular, and that is a promise
//
// Run:  scripts/run.sh 04-integer-types/08_unsigned_wrap.c
// -----------------------------------------------------------------------------
//
// Unsigned addition, subtraction, and multiplication are defined for every
// pair of values. The result is reduced modulo one past the maximum: for
// unsigned int, modulo 2^32 on this platform, which is UINT_MAX + 1.
//
// So 0 - 1 is UINT_MAX, and UINT_MAX + 1 is 0. That wrap is not an error
// and not a warning. It is the arithmetic the type has.
//
// Signed arithmetic does not wrap (next file). A program that wants
// wraparound asks for it by using an unsigned type. A program that wants
// a diagnostic when a signed operation would overflow can use the checked
// arithmetic in <stdckdint.h>, which chapter 32 covers.

#include <limits.h>
#include <stdio.h>

int main(void) {
    unsigned u = 0;
    printf("%u\n", u - 1u);
    printf("%u\n", UINT_MAX);
    printf("%u\n", UINT_MAX + 1u);

    // The addition is done in a wider type (chapter 9). Storing the result
    // back into an unsigned char reduces it modulo 256, which is defined.
    unsigned char b = 255;
    b = (unsigned char)(b + 1);
    printf("%d\n", b);
    return 0;
}

// Output:
// 4294967295
// 4294967295
// 0
// 0

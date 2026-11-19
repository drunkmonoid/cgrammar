// -----------------------------------------------------------------------------
// 02_conversion_rank.c - which integer type outranks which
//
// Run:  scripts/run.sh 09-conversions/02_conversion_rank.c
// -----------------------------------------------------------------------------
//
// Every integer type has a conversion rank. The usual arithmetic
// conversions, in the next file, use the rank to decide which operand
// changes type.
//
//     long long and unsigned long long
//     long and unsigned long
//     int and unsigned int
//     short and unsigned short
//     signed char, char, unsigned char
//     bool
//
// A wider standard type outranks a narrower one. The unsigned twin has
// the same rank as the signed type. A bit-precise type outranks every
// standard type of smaller width; its rank against a standard type of
// equal or greater width is not something to guess, which is why file 06
// of chapter 4 prints the result of a mixed addition instead of the rank.
//
// Rank is not size. On this platform long and long long have the same
// size and different ranks: long long outranks long. That matters when
// one of them is unsigned. long long cannot represent every unsigned long,
// because both are 64 bits and the unsigned one uses the sign bit for
// magnitude. The conversions therefore produce an unsigned long long, and
// a negative long long becomes a large positive value.
//
// The other way round is the one people expect. unsigned int outranks
// nothing that long does not already outrank, and a 64-bit long can hold
// every unsigned int. -1L + 1u is 0, not a value near 2^64.

#include <stdio.h>

int main(void) {
    long long negative = -1;
    unsigned long zero = 0;
    printf("%d\n", (negative + zero) > 0);

    long wide = -1;
    unsigned int one = 1;
    printf("%d\n", (wide + one) == 0);

    printf("%zu %zu\n", sizeof(negative + zero), sizeof(wide + one));
    return 0;
}

// Output:
// 1
// 1
// 8 8

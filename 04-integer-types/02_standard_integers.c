// -----------------------------------------------------------------------------
// 02_standard_integers.c - the five widths, signed and unsigned
//
// Run:  scripts/run.sh 04-integer-types/02_standard_integers.c
// -----------------------------------------------------------------------------
//
// The standard signed integer types, from narrowest rank to widest, are
//
//     signed char, short, int, long, long long
//
// "signed" is optional except on char, where it selects a different type
// (see 01). Each has an unsigned twin: unsigned char, unsigned short,
// unsigned int, unsigned long, unsigned long long. "short int" and
// "long int" mean the same as short and long. "long long" is not two
// longs; it is one type.
//
// The standard guarantees minimum ranges, not exact sizes:
//
//     char        at least 8 bits
//     short       at least 16
//     int         at least 16
//     long        at least 32
//     long long   at least 64
//
// Each wider type is at least as wide as the one before it. On x86-64
// Linux the sizes are 1, 2, 4, 8, and 8: long and long long match, and
// int is 32 bits. A program that needs an exact width asks <stdint.h>
// for it (file 05), not long.
//
// Unsigned types use the same number of bits as their signed twin, so
// they can represent more positive values and no negative ones.

#include <stdio.h>

int main(void) {
    printf("%zu %zu %zu %zu %zu\n",
           sizeof(char), sizeof(short), sizeof(int),
           sizeof(long), sizeof(long long));
    printf("%zu %zu\n", sizeof(unsigned), sizeof(unsigned long long));

    short s = 1;
    long long wide = 1;
    printf("%d %d\n", (int)s, (int)(wide == 1LL));
    return 0;
}

// Output:
// 1 2 4 8 8
// 4 8
// 1 1

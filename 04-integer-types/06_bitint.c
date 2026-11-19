// -----------------------------------------------------------------------------
// 06_bitint.c - an integer whose width you choose
//
// Run:  scripts/run.sh 04-integer-types/06_bitint.c
// -----------------------------------------------------------------------------
//
// _BitInt(N) is a signed integer of exactly N value bits, N at least 2.
// unsigned _BitInt(N) allows N at least 1. There is no padding in the
// value, though the object may be larger than N bits: the size is rounded
// up to a size the machine can load. Here _BitInt(3) and _BitInt(24)
// occupy 1 and 4 bytes, and _BitInt(128) occupies 16.
//
// BITINT_MAXWIDTH, from <limits.h>, is the widest N the implementation
// supports. It is at least the width of long long. gcc and clang disagree
// about how much larger, so this program only checks the promise.
//
// A bit-precise value is not promoted to int the way a short is. Two
// unsigned _BitInt(3) values added together wrap at 8, and the sum still
// has that width. Mixed with an int, the usual arithmetic conversions do
// apply, and a narrow bit-int is converted to the int. The wb suffix from
// chapter 3 spells a constant of such a type.
//
// Signed overflow is undefined behaviour here as it is for int. The
// unsigned wrap below is defined.

#include <limits.h>
#include <stdio.h>

int main(void) {
    _BitInt(3) s = -4;
    unsigned _BitInt(3) u = 7;
    printf("%d %u\n", (int)s, (unsigned)u);

    unsigned _BitInt(3) sum = u + 1;
    printf("%u %zu\n", (unsigned)sum, sizeof(u + (unsigned _BitInt(3))1));

    // The literal 1 has type int, so this addition is done as int.
    printf("%d %zu\n", (int)(u + 1), sizeof(u + 1));

    printf("%zu %zu %zu %zu\n",
           sizeof(_BitInt(3)), sizeof(_BitInt(24)),
           sizeof(_BitInt(64)), sizeof(_BitInt(128)));
    printf("%d\n", BITINT_MAXWIDTH >= LLONG_WIDTH);
    return 0;
}

// Output:
// -4 7
// 0 1
// 8 4
// 1 4 8 16
// 1

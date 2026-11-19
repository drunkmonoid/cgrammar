// -----------------------------------------------------------------------------
// 02_integer_suffixes.c - which type an integer constant has
//
// Run:  scripts/run.sh 03-constants-and-literals/02_integer_suffixes.c
// -----------------------------------------------------------------------------
//
// No suffix, and the compiler picks the first type in a list that can hold
// the value.
//
//   decimal                  int, long, long long
//   octal, hex, binary       int, unsigned int, long, unsigned long,
//                            long long, unsigned long long
//
// Decimal never tries an unsigned type. 2147483648 is one past INT_MAX, so
// it is a long on this platform, where long is 64 bits. The same value
// written as hex, 0x80000000, does fit in unsigned int, and hex tries that
// before long, so the constant is an unsigned int. Same bits, two types.
// That difference is why 0x80000000 compared with -1 surprises people, and
// why a decimal and a hex spelling of one number need not have one type.
//
// A suffix forces the search to start later:
//
//     u    unsigned int, then unsigned long, then unsigned long long
//     l    long, then long long
//     ll   long long
//     ul   unsigned long, then unsigned long long
//     ull  unsigned long long
//
// u and l may be written in either order and either case: 1uLL is fine.
//
// wb (C23) means a signed bit-precise type, the narrowest _BitInt(N) with
// N >= 2 that can hold the value. uwb is the unsigned version, N >= 1.
// 1wb is not an int. Bit-precise types themselves are chapter 4.
//
// On x86-64 Linux, long and long long are both 8 bytes, so sizeof cannot
// tell them apart. The lists above are still the rule.

#include <stdio.h>

int main(void) {
    printf("unsuffixed: %zu %zu %zu\n",
           sizeof(1), sizeof(2147483647), sizeof(2147483648));
    printf("hex of 2^31: %zu\n", sizeof(0x80000000));
    printf("binary of 2^31: %zu\n",
           sizeof(0b10000000000000000000000000000000));

    printf("suffixes: %zu %zu %zu %zu %zu\n",
           sizeof(1u), sizeof(1l), sizeof(1ll), sizeof(1ul), sizeof(1ull));

    printf("bit-precise: %zu %zu %d\n", sizeof(1wb), sizeof(255uwb), (int)100wb);
    return 0;
}

// Output:
// unsuffixed: 4 4 8
// hex of 2^31: 4
// binary of 2^31: 4
// suffixes: 4 8 8 8 8
// bit-precise: 1 1 100

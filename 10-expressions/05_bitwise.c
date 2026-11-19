// -----------------------------------------------------------------------------
// 05_bitwise.c - and, or, xor, and complement, on the value bits
//
// Run:  scripts/run.sh 10-expressions/05_bitwise.c
// -----------------------------------------------------------------------------
//
// & | ^ ~ operate on the bits of integer operands. They do not short-circuit.
// Both operands of & | ^ are evaluated, and ~ has one.
//
//     0b1100 & 0b1010    bits set in both        0b1000
//     0b1100 | 0b1010    bits set in either      0b1110
//     0b1100 ^ 0b1010    bits set in one         0b0110
//
// ~ flips every value bit. ~0 is an int with every bit set, which in two's
// complement is -1. ~0u is an unsigned int with every bit set, which is
// UINT_MAX. The operand's type decides which of those you get. Prefer the
// unsigned form when you mean "all bits".
//
// A common way to read one bit is to shift it down and mask with 1.
// (x >> 2) & 1u is bit 2 of x, counting from zero at the low end.
//
// These operators are not the logical operators. & is not &&. The next
// file is the logical ones, which yield 0 or 1 and may skip an operand.

#include <stdio.h>

int main(void) {
    printf("%d %d %d\n", 0b1100 & 0b1010, 0b1100 | 0b1010, 0b1100 ^ 0b1010);
    printf("%d %u\n", ~0, ~0u);

    unsigned x = 0b101100u;
    printf("%u\n", (x >> 2) & 1u);
    return 0;
}

// Output:
// 8 14 6
// -1 4294967295
// 1

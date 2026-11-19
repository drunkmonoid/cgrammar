// -----------------------------------------------------------------------------
// 02_arithmetic.c - addition, subtraction, multiplication, and unary sign
//
// Run:  scripts/run.sh 10-expressions/02_arithmetic.c
// -----------------------------------------------------------------------------
//
// + - * / % are the arithmetic operators. This file is the three that have
// no further rule about rounding or remainder. Division and remainder are
// the next file. The type of each operation is decided by the usual
// arithmetic conversions (chapter 9), not by these operators.
//
// Unary + and unary - are operators too. Unary + yields the value of its
// operand after the integer promotions, which makes it a way to promote
// and do nothing else. Unary - negates. Negating a value that cannot be
// represented, in particular INT_MIN, is undefined (chapter 4).
//
// The operators associate left to right, so 8 - 3 - 1 is (8 - 3) - 1.
// Precedence, including the fact that * binds tighter than +, is file 11.

#include <stdio.h>

int main(void) {
    printf("%d %d %d\n", 8 + 3, 8 - 3, 8 * 3);
    printf("%d\n", 8 - 3 - 1);
    printf("%d %d\n", -8, +8);

    char c = 1;
    printf("%zu %zu\n", sizeof c, sizeof(+c));
    return 0;
}

// Output:
// 11 5 24
// 4
// -8 8
// 1 4

// -----------------------------------------------------------------------------
// 11_precedence.c - which operator binds tighter
//
// Run:  scripts/run.sh 10-expressions/11_precedence.c
// -----------------------------------------------------------------------------
//
// Precedence decides which operator takes an operand when two of them
// could. Associativity decides the grouping when the operators have the
// same precedence. The parentheses below are the grouping the language
// would have chosen. File 12 writes the same expressions without them,
// which is legal and harder to read; both compilers warn about those.
//
// Highest precedence first, grouping the rows that share a precedence.
// Prefix operators associate right to left. Postfix associate left to
// right.
//
//     () [] . -> ++ --              postfix
//     ! ~ + - ++ -- * & sizeof      prefix, and the casts
//     * / %
//     + -
//     << >>
//     < <= > >=
//     == !=
//     &
//     ^
//     |
//     &&
//     ||
//     ?:
//     = += -= *= /= %= <<= >>= &= ^= |=
//     ,
//
// Two consequences that surprise people, both printed below. << binds
// looser than +, so 1 << (2 + 1) is the parenthesization, and the shift
// is by 3. == binds tighter than &, so 5 & (3 == 1) masks with the
// comparison's result, which is 0, rather than comparing a masked value.
//
// Assignment and the conditional operator associate right to left.
// Everything from * down to || associates left to right.

#include <stdio.h>

int main(void) {
    printf("%d\n", 2 + 3 * 4);
    printf("%d\n", (2 + 3) * 4);
    printf("%d\n", 1 << (2 + 1));
    printf("%d\n", (1 + 2) << 1);
    printf("%d\n", 5 & (3 == 1));
    printf("%d\n", (5 & 3) == 1);
    return 0;
}

// Output:
// 14
// 20
// 8
// 6
// 0
// 1

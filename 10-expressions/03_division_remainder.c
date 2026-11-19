// -----------------------------------------------------------------------------
// 03_division_remainder.c - truncation toward zero, and the identity that follows
//
// Run:  scripts/run.sh 10-expressions/03_division_remainder.c
// -----------------------------------------------------------------------------
//
// Integer division truncates toward zero. 7/3 is 2. -7/3 is -2, not -3:
// the result is the integer of smaller magnitude, and the sign follows the
// mathematical quotient.
//
// The remainder has the sign of the dividend, and it satisfies
//
//     (a / b) * b + (a % b) == a
//
// for every defined pair. -7 divided by 3 is -2 with remainder -1, because
// -2 * 3 + -1 is -7. 7 divided by -3 is -2 with remainder 1, because
// -2 * -3 + 1 is 7.
//
// Both operands of % must have integer type. A floating remainder is
// fmod, from <math.h>, and it is a later chapter.
//
// Division by zero, and a remainder with a zero divisor, are undefined
// for integers. Floating division by zero is defined and yields an
// infinity (chapter 5). The program does not divide by zero: a sanitizer
// would catch it, and so would the processor, and neither of those is the
// lesson. The lesson is to not do it.

#include <stdio.h>

int main(void) {
    printf("%d %d\n", 7 / 3, 7 % 3);
    printf("%d %d\n", -7 / 3, -7 % 3);
    printf("%d %d\n", 7 / -3, 7 % -3);

    int a = -7;
    int b = 3;
    printf("%d\n", (a / b) * b + (a % b) == a);
    return 0;
}

// Output:
// 2 1
// -2 -1
// -2 1
// 1

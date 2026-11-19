// -----------------------------------------------------------------------------
// 09_signed_overflow.c - signed overflow is undefined behaviour
//
// Run:  scripts/run.sh 04-integer-types/09_signed_overflow.c
// -----------------------------------------------------------------------------
// @san fail
//
// If a signed addition, subtraction, multiplication, or negation cannot be
// represented in the result type, the behaviour is undefined. The program
// is not required to wrap, to trap, or to produce a value at all. The
// compiler may assume the overflow never happens and delete the test that
// would have noticed it.
//
// INT_MAX + 1 cannot be represented. So can -INT_MIN. Neither is a defined
// way to reach the other end of the range; the unsigned conversion in the
// previous file is.
//
// This program performs the addition anyway. Without a sanitizer it
// happens to continue, which proves nothing: undefined behaviour includes
// "seems to work". Built with SAN=1, the undefined-behaviour sanitizer
// stops it. The check script expects that.

#include <limits.h>
#include <stdio.h>

int main(void) {
    puts("before");

    volatile int x = INT_MAX;
    volatile int y = x + 1;
    if (y == 0) {
        puts("zero");
    }

    puts("after");
    return 0;
}

// Output:
// before
// after

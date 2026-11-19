// -----------------------------------------------------------------------------
// 06_relational_logical.c - comparisons, and the operators that skip an operand
//
// Run:  scripts/run.sh 10-expressions/06_relational_logical.c
// -----------------------------------------------------------------------------
//
// < > <= >= == != compare their operands and yield the int 1 or the int 0.
// They do not yield the lesser operand. The result has type int even when
// the operands are floating.
//
// && and || are the logical operators. They also yield 0 or 1, never the
// value of an operand: 0 || 3 is 1. They evaluate the right operand only
// when the left has not already decided the result.
//
//     left && right     right is evaluated only when left is nonzero
//     left || right     right is evaluated only when left is zero
//
// The skipped operand is not evaluated at all. A side effect in it does
// not happen, and an undefined operation in it does not run. That is the
// reason if (p && *p) is safe when p is null, and if (p & *p) is not: &
// is the bitwise operator and evaluates both sides.
//
// ! yields 1 when its operand compares equal to zero, and 0 otherwise.
// !!n is 1 for any nonzero n and 0 for zero, which is the conversion to
// bool written as an int.

#include <stdio.h>

static int calls = 0;

static int bump(void) {
    calls += 1;
    return 1;
}

int main(void) {
    printf("%d %d %d\n", 1 < 2, 1 == 2, 1 != 2);

    printf("%d\n", 0 && bump());
    printf("%d\n", calls);
    printf("%d\n", 1 || bump());
    printf("%d\n", calls);
    printf("%d\n", 1 && bump());
    printf("%d\n", calls);

    printf("%d %d %d\n", !0, !1, !5);

    // Variables, so the operands are not integer constant expressions.
    // A constant on the right of || is diagnosed by clang; the result is
    // the same either way. 0 || 3 would be 1, not 3.
    int zero = 0;
    int three = 3;
    printf("%d\n", zero || three);
    return 0;
}

// Output:
// 1 0 1
// 0
// 0
// 1
// 0
// 1
// 1
// 1 0 0
// 1

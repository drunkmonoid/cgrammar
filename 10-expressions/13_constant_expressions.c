// -----------------------------------------------------------------------------
// 13_constant_expressions.c - values the compiler must be able to fold
//
// Run:  scripts/run.sh 10-expressions/13_constant_expressions.c
// -----------------------------------------------------------------------------
//
// An integer constant expression is built from integer constants, character
// constants, enumeration constants, sizeof of a type that is not a VLA,
// alignof, and the operators that do not depend on a runtime value. Casts
// to integer types are allowed. Assignment, increment, function calls, and
// the comma operator are not.
//
// The places that require one:
//
//     the length of an array that is not a VLA
//     a case label
//     a bit-field width
//     the operand of static_assert and alignas
//     the value of an enumeration constant
//     the initializer of a constexpr integer
//
// A floating constant is not an integer constant expression, even when its
// value is a whole number. (int)1.0 is a cast of a floating constant; it
// is an arithmetic constant expression, and it is not an integer constant
// expression, so it cannot be a case label.
//
// The expressions below are integer constant expressions. The switch
// selects on one, the array length is one, and alignas consumes one.

#include <stdint.h>
#include <stdio.h>

constexpr int n = 3;

int main(void) {
    static_assert(n * n == 9, "folded");

    int a[2 + 2];
    int x = 4;
    int label;

    switch (x) {
    case 2 * 2:
        label = 1;
        break;
    default:
        label = 0;
        break;
    }

    alignas(4 * 2) unsigned char buf[1];
    printf("%zu %d %d\n",
           sizeof a / sizeof a[0], label, (int)((uintptr_t)buf % 8 == 0));
    return 0;
}

// Output:
// 4 1 1

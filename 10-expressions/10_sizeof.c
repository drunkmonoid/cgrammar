// -----------------------------------------------------------------------------
// 10_sizeof.c - the size of a type, and when the operand is evaluated
//
// Run:  scripts/run.sh 10-expressions/10_sizeof.c
// -----------------------------------------------------------------------------
//
// sizeof yields a size_t: the number of bytes in an object of the operand's
// type. sizeof(int) and sizeof n, for an int n, are the same value. The
// parentheses are required when the operand is a type and optional when
// it is an expression. This repository always writes them.
//
// The operand is not evaluated, unless it is a variable-length array.
// sizeof(n + 1) does not add. sizeof of a VLA does compute the length,
// because the length is not a constant and the size depends on it. The
// increment below runs, and it runs because the type is a VLA, not because
// sizeof evaluates expressions in general.
//
// sizeof of an array is the whole array. The decay to a pointer (chapter 9)
// does not apply to the operand of sizeof. sizeof of a pointer is the
// pointer. That difference is how a function that received an array as a
// pointer loses the length: the parameter never was an array.

#include <stdio.h>

int main(void) {
    int n = 0;
    int m = 3;

    printf("%zu %zu\n", sizeof n, sizeof(int));
    printf("%zu\n", sizeof(int[4]));
    printf("%zu\n", sizeof(n + 1));
    printf("%d\n", n);

    printf("%zu\n", sizeof(int[m]));
    printf("%zu\n", sizeof(int[m++]));
    printf("%d\n", m);
    return 0;
}

// Output:
// 4 4
// 16
// 4
// 0
// 12
// 12
// 4

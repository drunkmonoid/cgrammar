// -----------------------------------------------------------------------------
// 04_evaluation.c - the precision of an intermediate result
//
// Run:  scripts/run.sh 05-floating-types/04_evaluation.c
// -----------------------------------------------------------------------------
//
// FLT_EVAL_METHOD says how much precision an expression may use beyond the
// type of its operators.
//
//     -1   indeterminable
//      0   each operation is evaluated to the range and precision of its type
//      1   float and double operations may be evaluated as double
//      2   float and double operations may be evaluated as long double
//
// This platform reports 0. A float addition really is a float addition:
// the extra bits of a long double register are not kept. That is the
// behaviour to write portable code for. A method of 1 or 2 would let
// (a + b) + c differ from a stored intermediate, because the sum a + b
// would still be holding bits that a float cannot.
//
// The method does not change the type of the expression. 1.0f + 2.0f has
// type float either way. It changes which value that float is allowed to
// be rounded from.
//
// Casting an intermediate result to the type, or storing it, forces the
// rounding even when the method is not 0. Under method 0 the cast changes
// nothing.

#include <float.h>
#include <stdio.h>

int main(void) {
    printf("%d\n", FLT_EVAL_METHOD);

    float big = 1e30f;
    float one = 1.0f;
    float stored = big + one;
    printf("%d\n", stored == big);
    printf("%zu\n", sizeof(big + one));
    return 0;
}

// Output:
// 0
// 1
// 4

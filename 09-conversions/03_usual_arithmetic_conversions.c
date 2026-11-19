// -----------------------------------------------------------------------------
// 03_usual_arithmetic_conversions.c - one type for both operands
//
// Run:  scripts/run.sh 09-conversions/03_usual_arithmetic_conversions.c
// -----------------------------------------------------------------------------
//
// An arithmetic operator needs both operands to have the same type. The
// usual arithmetic conversions pick that type. The rules, in order:
//
//   1. If either operand has type long double, the other is converted to
//      long double. Otherwise double, otherwise float.
//   2. Otherwise the integer promotions are applied.
//   3. If the types are then the same, that is the type.
//   4. If both are signed or both are unsigned, the one with greater rank
//      wins.
//   5. If the unsigned operand's rank is greater or equal, the signed
//      operand converts to that unsigned type.
//   6. If the signed operand can represent every value of the unsigned
//      operand, the unsigned one converts to the signed type.
//   7. Otherwise both convert to the unsigned type of the signed operand.
//
// Rule 1 is why 1 + 2.0f has type float and 1.0f + 2.0 has type double.
// The integer is converted to the floating type, not the other way round.
// Rules 5 to 7 are the signed-against-unsigned cases. The next file shows
// what they do to a negative value.
//
// The type of the expression is the type these rules produce. It does not
// depend on what the result is stored into. Assigning a double expression
// to a float converts again, after the operation.

#include <stdio.h>

int main(void) {
    printf("%zu %zu %zu\n", sizeof(1 + 2.0f), sizeof(1.0f + 2.0), sizeof(1.0f + 1.0L));

    int i = 1;
    double d = 2.5;
    printf("%.1f\n", i + d);
    return 0;
}

// Output:
// 4 8 16
// 3.5

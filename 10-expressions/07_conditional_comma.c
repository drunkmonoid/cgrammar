// -----------------------------------------------------------------------------
// 07_conditional_comma.c - the two operators that contain another expression
//
// Run:  scripts/run.sh 10-expressions/07_conditional_comma.c
// -----------------------------------------------------------------------------
//
// The conditional operator, ?: , evaluates one of its last two operands.
//
//     condition ? then-value : else-value
//
// The condition is converted to bool. Exactly one of the other two
// expressions is evaluated. Their types are brought together by a rule
// close to the usual arithmetic conversions: 1 and 1.0 produce a double,
// so the type of the whole expression is double and sizeof of it is 8.
//
// The comma operator evaluates its left operand, discards the value, and
// yields the right operand. There is a sequence point between them: the
// side effects of the left are complete before the right is evaluated.
// The commas that separate function arguments and initializer elements
// are not this operator. Those are punctuation. The comma operator is
// the one in an expression, usually inside parentheses, because it has
// the lowest precedence of all.
//
// Both operators associate right to left. a ? b : c ? d : e is
// a ? b : (c ? d : e).

#include <stdio.h>

int main(void) {
    printf("%d\n", 0 ? 10 : 20);
    printf("%zu\n", sizeof(1 ? 1 : 1.0));

    int n = 1;
    int r = (n += 2, n * 3);
    printf("%d %d\n", n, r);

    printf("%d\n", 1 ? 2 : 3 ? 4 : 5);
    return 0;
}

// Output:
// 20
// 8
// 3 9
// 2

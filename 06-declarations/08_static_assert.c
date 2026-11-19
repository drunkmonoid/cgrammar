// -----------------------------------------------------------------------------
// 08_static_assert.c - a check that runs during translation
//
// Run:  scripts/run.sh 06-declarations/08_static_assert.c
// -----------------------------------------------------------------------------
//
// static_assert(expression) stops translation if the expression is zero.
// static_assert(expression, "message") does the same and uses the message
// in the diagnostic. The expression must be an integer constant expression.
//
// It may appear wherever a declaration may: at file scope, in a block, and
// inside a struct. It does not reserve storage and does not produce code.
// A failed assertion is a compile error, the same kind as a type error.
// It is not a branch the program can take.
//
// The form without a message is C23. C11 required the string. The keyword
// _Static_assert is the older spelling of the same thing, and it still
// requires the message.
//
// What belongs here is a fact the program is built on: a size, a width,
// the layout of a constant. A check that depends on input belongs in a
// test, or in assert from <assert.h>, which chapter 31 covers.

#include <limits.h>
#include <stdio.h>

static_assert(sizeof(int) >= 2, "int is at least 16 bits");
static_assert(CHAR_BIT == 8);

struct pair {
    int x;
    int y;
    static_assert(sizeof(int) == 4, "the sizes printed below assume this");
};

int main(void) {
    static_assert(sizeof(struct pair) >= 2 * sizeof(int));
    printf("%zu\n", sizeof(struct pair));
    return 0;
}

// Output:
// 8

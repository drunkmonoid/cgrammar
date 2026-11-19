// -----------------------------------------------------------------------------
// 08_assignment.c - an expression whose value is what was stored
//
// Run:  scripts/run.sh 10-expressions/08_assignment.c
// -----------------------------------------------------------------------------
//
// Assignment stores a value in the object an lvalue designates, and the
// value of the assignment expression is the value that was stored. That
// is why a = b = 4 works: = associates right to left, so this is a = (b = 4),
// and the value of b = 4 is 4.
//
// The compound assignments operate on the current value and store the
// result. x += 3 means x = x + 3, except that the lvalue is evaluated
// once. The same form exists for - * / % << >> & ^ |.
//
// ++ and -- add or subtract one. The prefix form yields the new value.
// The postfix form yields the old value, then updates the object. Both
// require an lvalue. The update is a side effect, and chapter 11 is about
// when side effects are guaranteed to have happened. This file only uses
// them in separate statements, where the next statement is a sequence
// point and the update has happened.

#include <stdio.h>

int main(void) {
    int a;
    int b;
    printf("%d\n", a = b = 4);
    printf("%d %d\n", a, b);

    int x = 10;
    x += 3;
    x *= 2;
    x -= 4;
    printf("%d\n", x);

    int n = 5;
    printf("%d\n", n++);
    printf("%d\n", n);
    printf("%d\n", ++n);
    printf("%d\n", n);
    return 0;
}

// Output:
// 4
// 4 4
// 22
// 5
// 6
// 7
// 7

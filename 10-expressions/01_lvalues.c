// -----------------------------------------------------------------------------
// 01_lvalues.c - an expression that designates an object
//
// Run:  scripts/run.sh 10-expressions/01_lvalues.c
// -----------------------------------------------------------------------------
//
// An lvalue designates an object. The operators that modify an object, or
// that take its address, require one: assignment, increment, decrement,
// and unary &.
//
// These expressions are lvalues:
//
//     n          the name of an object
//     *p         the object a pointer points at
//     a[i]       *(a + i), so the same
//     p->m       a member of the object a pointer points at
//     s.m        a member, when s itself is an lvalue
//
// These are not:
//
//     1 + 2      a value, with no object
//     n + 0      the value read from n
//     42         a constant
//     a function call that returns an int
//
// The result of an assignment is not an lvalue in C. It is in C++. The
// file 13_not_an_lvalue.c is the constraint those operators enforce.

#include <stdio.h>

struct pair {
    int x;
    int y;
};

int main(void) {
    int n = 1;
    n = 2;

    int *p = &n;
    *p = 3;

    int a[1];
    a[0] = 4;

    struct pair s = {5, 6};
    struct pair *sp = &s;
    sp->y = 7;

    printf("%d %d %d %d\n", n, a[0], s.x, s.y);
    return 0;
}

// Output:
// 3 4 5 7

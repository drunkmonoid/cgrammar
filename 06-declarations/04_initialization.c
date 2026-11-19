// -----------------------------------------------------------------------------
// 04_initialization.c - the value an object has at the start of its lifetime
//
// Run:  scripts/run.sh 06-declarations/04_initialization.c
// -----------------------------------------------------------------------------
//
// An initializer is the = that follows a declarator. Without one, an
// automatic object has an indeterminate value, and reading it is undefined.
// A static object without an initializer is zeroed. Chapter 7 says which
// objects are static.
//
// The form of the initializer follows the shape of the type.
//
//     int n = 1;                 a scalar
//     int a[4] = {1, 2};         an aggregate; omitted elements are zero
//     int c[] = {1, 2, 3};       the length is taken from the list
//     struct pair q = {.y = 4};  a designator names the element
//
// C23 allows an empty initializer, {}. It means "zero of this type", for
// a scalar as well as for an aggregate. Before C23 a scalar had no brace
// form, and an aggregate needed at least a 0 inside the braces.
//
// Structures are a later chapter. The one here exists so an initializer
// has a member to name. A designator that is absent leaves that member
// zero, the same as an element past the end of a short list.

#include <stdio.h>

struct pair {
    int x;
    int y;
};

int main(void) {
    int n = {};
    int a[4] = {1, 2};
    int b[3] = {};
    int c[] = {1, 2, 3};
    struct pair q = {.y = 4};
    struct pair z = {};

    printf("%d %d %d %d\n", n, a[0], a[3], b[1]);
    printf("%d %zu %d %d\n", c[2], sizeof c / sizeof c[0], q.y, z.x);
    return 0;
}

// Output:
// 0 1 0 0
// 3 3 4 0

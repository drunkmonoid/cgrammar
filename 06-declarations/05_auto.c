// -----------------------------------------------------------------------------
// 05_auto.c - let the initializer say what the type is
//
// Run:  scripts/run.sh 06-declarations/05_auto.c
// -----------------------------------------------------------------------------
//
// In C23, auto as the only specifier means "the type of the initializer",
// after lvalue conversion, array decay, and function decay. The declaration
// must have an initializer. There is nothing else to take the type from.
//
//     auto x = 1;       int
//     auto y = 1.5;     double
//     auto u = 1u;      unsigned int
//
// Qualifiers on the source are not copied. A const int value stored into
// an auto object gives a plain int, which can be assigned to. The const
// was a property of the other object, and the value was copied out of it.
//
// An array decays, so auto p = a, where a is an array, gives a pointer.
// typeof, in the next file, does not decay. Use typeof when you wanted
// the array.
//
// auto next to a type specifier is the old, redundant storage-class
// specifier meaning "automatic". auto int n = 1 still means int n = 1.
// The inference form is the one with no type written beside it.

#include <stdio.h>

int main(void) {
    auto x = 1;
    auto y = 1.5;
    auto u = 1u;

    const int c = 3;
    auto z = c;
    z = 4;

    int a[3] = {10, 20, 30};
    auto p = a;

    auto int n = 5;

    printf("%zu %zu %zu\n", sizeof x, sizeof y, sizeof u);
    printf("%d %zu %d %d\n", z, sizeof p, p[1], n);
    return 0;
}

// Output:
// 4 8 4
// 4 8 20 5

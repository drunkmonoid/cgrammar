// -----------------------------------------------------------------------------
// 07_constexpr.c - an object that is a constant expression
//
// Run:  scripts/run.sh 06-declarations/07_constexpr.c
// -----------------------------------------------------------------------------
//
// constexpr is a storage-class specifier for objects. The initializer must
// be a constant expression, or a string literal for an array of char.
// The object is implicitly const: assigning to it is a constraint violation.
//
// A constexpr int is an integer constant expression. It may be the length
// of an array, the value of a case label, the operand of static_assert,
// and the alignment passed to alignas. An ordinary const int may not.
// const means "you promised not to write it". constexpr means "the
// compiler has the value".
//
// C23 does not have constexpr functions. A function that returns a
// constant is an ordinary function; the constant is the object it
// initializes. gcc and clang both reject constexpr on a function.
//
// A constexpr object may be declared at file scope or at block scope.
// Either way the value is usable wherever a constant is required.

#include <stdio.h>

constexpr int width = 4;
constexpr int squares[] = {1, 4, 9};

int main(void) {
    constexpr int n = 5;
    int a[n];
    int column;

    static_assert(width == 4, "width");
    static_assert(sizeof squares / sizeof squares[0] == 3);

    switch (n) {
    case width + 1:
        column = 1;
        break;
    default:
        column = 0;
        break;
    }

    a[0] = squares[2];
    printf("%d %zu %d\n", n, sizeof a / sizeof a[0], column);
    printf("%d\n", a[0]);
    return 0;
}

// Output:
// 5 5 1
// 9

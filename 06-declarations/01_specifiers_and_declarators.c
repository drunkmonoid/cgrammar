// -----------------------------------------------------------------------------
// 01_specifiers_and_declarators.c - a declaration is two jobs written together
//
// Run:  scripts/run.sh 06-declarations/01_specifiers_and_declarators.c
// -----------------------------------------------------------------------------
//
// A declaration names a thing and says what it is. The specifiers and
// qualifiers describe the type at the bottom of that description:
//
//     int, long, unsigned, double, bool, struct tags, typedef names
//     const, volatile, restrict, _Atomic
//     the storage-class specifiers: auto, static, extern, ...
//
// The declarator wraps that base type in pointers, arrays, and functions,
// and it is where the name sits. The name is in the middle, not at the
// front.
//
//     int *p;          p is a pointer to int
//     int a[4];        a is an array of 4 int
//     int f(int);      f is a function taking int and returning int
//
// Several declarators may share one list of specifiers. Each declarator
// is independent: in `int *p, a[4];` only p is a pointer. The * binds to
// the name, not to the int.
//
// A declaration that reserves storage is a definition. `int n = 1;` is
// both. `extern int n;` is a declaration and not a definition. Chapter 7
// is about how many definitions a name may have.

#include <stdio.h>

int value(int n);

int main(void) {
    int *p, a[4];
    int n = 1;
    p = &n;
    a[0] = *p;

    printf("%d %zu %zu %d\n", a[0], sizeof p, sizeof a, value(41));
    return 0;
}

int value(int n) {
    return n + 1;
}

// Output:
// 1 8 16 42

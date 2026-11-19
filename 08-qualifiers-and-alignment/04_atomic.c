// -----------------------------------------------------------------------------
// 04_atomic.c - _Atomic as a qualifier
//
// Run:  scripts/run.sh 08-qualifiers-and-alignment/04_atomic.c
// -----------------------------------------------------------------------------
//
// _Atomic qualifies a type, or it is written as a specifier with the type
// in parentheses. The two forms name the same type.
//
//     _Atomic int x;
//     _Atomic(int) y;
//
// An access to an atomic object is indivisible with respect to other
// accesses to the same object. The addition below is an atomic
// read-modify-write. A signal handler, or another thread, cannot observe
// a half-updated int.
//
// That is all this file claims. Memory ordering, the difference between
// a data race and a synchronized access, and the operations in
// <stdatomic.h> are chapter 38. _Atomic is the qualifier; the header is
// the library.
//
// The qualifier is part of the type. typeof_unqual removes it.
// sizeof(_Atomic int) is at least sizeof(int), and on this platform it is
// equal: an int needs no extra lock in the object.

#include <stdio.h>

int main(void) {
    _Atomic int x = 1;
    _Atomic(int) y = 2;

    x += 1;
    y += 3;

    printf("%d %d\n", x, y);
    printf("%zu\n", sizeof(_Atomic int));
    return 0;
}

// Output:
// 2 5
// 4

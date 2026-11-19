// -----------------------------------------------------------------------------
// 05_qualified_pointers.c - the qualifier can sit at every level
//
// Run:  scripts/run.sh 08-qualifiers-and-alignment/05_qualified_pointers.c
// -----------------------------------------------------------------------------
//
// Each * in a declarator introduces a pointer, and each pointer has its
// own qualifiers. Read from the name outward, the same way as chapter 6.
//
//     const int *p              pointer to const int
//     int *const p              const pointer to int
//     const int *const p        const pointer to const int
//     const int *const *p       pointer to const pointer to const int
//
// A conversion may add qualifiers at the level being pointed to.
// int * converts to const int *. It may not add them deeper in a way that
// would let a const object be reached through a non-const path. int **
// does not convert to const int **. If it did, a const int could be
// stored into an int * by going through the extra pointer. The constraint
// is what stops that.
//
// The same rule applies to volatile, restrict, and _Atomic.

#include <stdio.h>

int main(void) {
    int v = 1;
    const int cv = 2;

    int *p = &v;
    const int *pc = p;
    int *const cp = &v;
    const int *const *ppc = &pc;

    pc = &cv;
    *p = 5;

    printf("%d %d %d %d\n", *p, *pc, *cp, **ppc);
    return 0;
}

// Output:
// 5 2 5 2

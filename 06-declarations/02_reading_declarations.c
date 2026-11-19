// -----------------------------------------------------------------------------
// 02_reading_declarations.c - start at the name and walk outward
//
// Run:  scripts/run.sh 06-declarations/02_reading_declarations.c
// -----------------------------------------------------------------------------
//
// Read a declarator from the name, honouring parentheses, then alternate
// right and left.
//
//     int *ap[4];     ap is an array of 4 pointers to int
//     int (*pa)[4];   pa is a pointer to an array of 4 int
//     int *pick(int); pick is a function taking int and returning a pointer
//
// The postfix operators [] and () bind tighter than the prefix *. The
// parentheses in (*pa) exist to beat that. Without them the array or the
// function is on the inside.
//
// The sizes printed below are the check. A pointer is 8 bytes here. An
// array of 4 int is 16. An array of 4 pointers is 32. What pa points at
// is an array of 4 int, so sizeof *pa is 16 again.
//
// Pointers to functions come back in chapter 20. The reading rule does
// not change.

#include <stdio.h>

int *pick(int *start) {
    return start;
}

int main(void) {
    int *ap[4];
    int storage[4] = {1, 2, 3, 4};
    int (*pa)[4] = &storage;

    ap[0] = pick(storage);

    printf("%zu %zu %zu\n", sizeof ap, sizeof pa, sizeof *pa);
    printf("%d %d\n", ap[0][3], (*pa)[3]);
    return 0;
}

// Output:
// 32 8 16
// 4 4

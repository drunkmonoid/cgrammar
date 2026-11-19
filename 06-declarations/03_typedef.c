// -----------------------------------------------------------------------------
// 03_typedef.c - a name for a type you have already described
//
// Run:  scripts/run.sh 06-declarations/03_typedef.c
// -----------------------------------------------------------------------------
//
// typedef is a storage-class specifier, but it does not reserve storage.
// It binds a name to the type a declarator would have had.
//
//     typedef int *ptr;      ptr is "pointer to int"
//     typedef int row[4];    row is "array of 4 int"
//
// After that, ptr and row are type names. They can appear wherever a
// specifier can, and they do not need the * or the [] again.
//
// The trap is qualifiers. const applies to the whole typedef name, and a
// typedef name is not a macro. const ptr is a const pointer to int: the
// pointer cannot be reseated, and the int can be written. It is not a
// pointer to const int. Writing const int * says that. The typedef hides
// the *, so the const cannot sneak in front of it.
//
// A typedef name and a variable may not share a name in the same scope.
// The name is an ordinary identifier.

#include <stdio.h>

typedef int *ptr;
typedef int row[4];

int main(void) {
    int v = 1;
    int w = 2;
    ptr p = &v;
    const ptr fixed = &v;
    row line = {1, 2, 3, 4};

    *fixed = 3;
    p = &w;

    printf("%d %d %d %zu\n", v, *p, line[3], sizeof(row));
    return 0;
}

// Output:
// 3 2 4 16

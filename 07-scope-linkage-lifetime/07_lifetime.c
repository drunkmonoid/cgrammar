// -----------------------------------------------------------------------------
// 07_lifetime.c - storage ends even if a copy of the address does not
//
// Run:  scripts/run.sh 07-scope-linkage-lifetime/07_lifetime.c
// -----------------------------------------------------------------------------
//
// The lifetime of an automatic object is the execution of its block. When
// execution leaves the block, the lifetime ends. A pointer to that object,
// or a pointer into it, becomes indeterminate. Using the pointer is
// undefined behaviour. Copying the value out first is the defined way to
// keep it: the copy is a different object.
//
// Returning the address of a local is the same mistake. gcc and clang
// diagnose it. They are not required to. The diagnostic is a warning, and
// this repository builds with -Werror, so the program would be rejected
// here; a compiler that stayed silent would still be conforming, and the
// program would still be wrong.
//
// A static object's lifetime is the whole execution. Taking its address
// and using it later is defined. The name can go out of scope; the object
// does not.

#include <stdio.h>

int *persistent_slot(void) {
    static int slot = 6;
    return &slot;
}

int main(void) {
    int saved;
    {
        int inner = 7;
        saved = inner;
    }
    printf("%d\n", saved);

    int *p = persistent_slot();
    printf("%d\n", *p);
    *p = 8;
    printf("%d\n", *persistent_slot());
    return 0;
}

// Output:
// 7
// 6
// 8

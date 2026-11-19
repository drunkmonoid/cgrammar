// -----------------------------------------------------------------------------
// 05_storage_class.c - the specifiers that are not part of the type
//
// Run:  scripts/run.sh 07-scope-linkage-lifetime/05_storage_class.c
// -----------------------------------------------------------------------------
//
// A declaration has at most one storage-class specifier. They are:
//
//     auto           at block scope with a type: automatic storage, which
//                    is the default. auto with no type is type inference
//                    (chapter 6), a different use of the same keyword.
//     constexpr      a constant object (chapter 6)
//     extern         linkage to a definition elsewhere, or at file scope
//                    a definition with external linkage when there is an
//                    initializer
//     register       automatic storage, and a hint that the object will be
//                    used heavily. The address of a register object cannot
//                    be taken. The hint is not a promise that a register
//                    is used.
//     static         static storage duration. At file scope it also gives
//                    internal linkage.
//     thread_local   thread storage duration. It may be combined with
//                    static or extern, which is the one exception to
//                    "at most one".
//     typedef        the declaration names a type instead of an object
//
// register is the one with a constraint you can trip in a single line.
// The next file but one is that line, and it must not compile.

#include <stdio.h>

static int helper(void) {
    return 2;
}

int global = 5;

int main(void) {
    auto int x = 1;
    register int y = 2;
    extern int global;
    thread_local static int t = 3;

    t += 1;
    printf("%d %d %d %d %d\n", x, y, global, helper(), t);
    return 0;
}

// Output:
// 1 2 5 2 4

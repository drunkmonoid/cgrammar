// -----------------------------------------------------------------------------
// 04_storage_duration.c - how long an object lives
//
// Run:  scripts/run.sh 07-scope-linkage-lifetime/04_storage_duration.c
// -----------------------------------------------------------------------------
//
// Storage duration is the lifetime of the storage, which is not the same
// as the scope of the name.
//
//   automatic    from entry to the block until execution leaves it.
//                Each entry starts a new lifetime. The value does not
//                survive, and without an initializer it is indeterminate.
//   static       for the whole execution of the program. Initialization
//                happens once, before or at the first entry. A static
//                object with no initializer is zero.
//   thread       for the execution of one thread. Each thread has its own
//                object. This program has one thread, so the object behaves
//                like a static one that other threads could not see.
//   allocated    from malloc until free. Chapter 21.
//
// static on a block-scope variable gives static storage duration and no
// linkage. The name is still local. The object is not: next below returns
// 1, then 2, then 3, because n is the same object every call.
//
// Argument evaluation order is unspecified, so the three calls are in
// separate statements. Written as one call, the numbers would be allowed
// to arrive in any order.

#include <stdio.h>

thread_local int per_thread = 10;

int next(void) {
    static int n = 0;
    n += 1;
    return n;
}

int main(void) {
    int a = next();
    int b = next();
    int c = next();
    printf("%d %d %d\n", a, b, c);

    per_thread += 1;
    printf("%d\n", per_thread);

    int saved;
    {
        int inner = 7;
        saved = inner;
    }
    printf("%d\n", saved);
    return 0;
}

// Output:
// 1 2 3
// 11
// 7

// -----------------------------------------------------------------------------
// 07_reserved_identifiers.c - names a program must not define
//
// Run:  scripts/run.sh 02-translation-and-lexical/07_reserved_identifiers.c
// -----------------------------------------------------------------------------
//
// Some identifiers belong to the implementation. Defining one of them
// yourself is undefined behaviour, and the compiler rarely says anything.
//
// Always reserved, in every scope:
//   - Names that start with two underscores:               __count
//   - Names that start with an underscore and a capital:   _Count
//
// Reserved at file scope (as global names, struct tags, typedefs):
//   - Every other name that starts with an underscore:     _count
//     Such a name is allowed for a local variable or a struct member.
//
// Reserved when the matching header is included, and as external names
// always:
//   - Everything the library declares: printf, malloc, errno, size_t, ...
//
// "Potentially reserved" (a C23 term): patterns that future versions of the
// library may claim. A program may use them today, and may break tomorrow:
//
//     str*  mem*  wcs*      followed by a lowercase letter   strip, member
//     is*   to*             followed by a lowercase letter   isle, total
//     E followed by a digit or capital                       ERROR, E2BIG
//     int*_t  uint*_t  atomic_*  memory_order_*  cnd_*  mtx_*  thrd_*  tss_*
//
// `total` and `member` are fine as local names. The risk is with external
// names and macros: do not write a function called `strip` or `toggle`, and
// do not define a macro called `ERROR`.
//
// The practical rule: never start a name with an underscore, and give your
// own external names a project prefix.

#include <stdio.h>

// A project prefix keeps clear of every reserved pattern.
static int cg_error_count = 0;

struct cg_point {
    int x;
    int y;
};

static void cg_report(const char *message) {
    cg_error_count++;
    printf("error %d: %s\n", cg_error_count, message);
}

int main(void) {
    // Allowed: an underscore followed by a lowercase letter, block scope.
    // Legal, but easy to get wrong, so not recommended.
    int _local = 5;

    struct cg_point p = {.x = 1, .y = 2};

    cg_report("first");
    cg_report("second");
    printf("_local = %d, p = (%d, %d)\n", _local, p.x, p.y);
    return 0;
}

// Output:
// error 1: first
// error 2: second
// _local = 5, p = (1, 2)

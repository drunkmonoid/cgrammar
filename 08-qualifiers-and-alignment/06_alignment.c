// -----------------------------------------------------------------------------
// 06_alignment.c - alignas, alignof, and the strictest fundamental alignment
//
// Run:  scripts/run.sh 08-qualifiers-and-alignment/06_alignment.c
// -----------------------------------------------------------------------------
//
// Every complete object type has an alignment: a number of bytes such that
// the address of an object of that type is a multiple of it. alignof names
// it. The operand is a type, in parentheses. alignof of an expression is
// a GNU extension, and -pedantic rejects it.
//
// alignas(N) requires an alignment of at least N. N is an integer constant
// expression, or a type, in which case the alignment of that type is used.
// The requirement can only be stricter. alignas(1) on an int is a
// constraint violation, because int already needs more than one byte of
// alignment. File 08 is that violation.
//
// max_align_t, from <stddef.h>, has the strictest alignment of any
// fundamental type. An allocation function is required to return storage
// suitable for it. On this platform that alignment is 16, the same as
// long double.
//
// A member with a stricter alignment pads the struct out to a multiple of
// that alignment. The sizes below are x86-64 Linux.

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

struct padded {
    alignas(16) char c;
};

int main(void) {
    printf("%zu %zu %zu %zu\n",
           alignof(char), alignof(int), alignof(double), alignof(max_align_t));

    alignas(32) unsigned char buf[8];
    printf("%d\n", (int)((uintptr_t)buf % 32 == 0));
    printf("%zu %zu\n", sizeof(struct padded), alignof(struct padded));
    return 0;
}

// Output:
// 1 4 8 16
// 1
// 16 16

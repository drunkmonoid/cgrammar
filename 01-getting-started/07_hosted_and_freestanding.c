// -----------------------------------------------------------------------------
// 07_hosted_and_freestanding.c - the two kinds of implementation
//
// Run:  scripts/run.sh 01-getting-started/07_hosted_and_freestanding.c
// -----------------------------------------------------------------------------
//
// The standard describes two execution environments.
//
// Hosted: there is an operating system underneath. The program starts in
// main, and the whole standard library is available. Everything in this
// tutorial is hosted unless it says otherwise.
//
// Freestanding: there may be nothing underneath (a kernel, firmware, a
// microcontroller). The name and type of the start function are
// implementation-defined, and only part of the library is required: the
// headers that need no operating system, such as <stddef.h>, <stdint.h>,
// <limits.h>, <float.h>, <stdarg.h>, <stdbit.h> and <stdckdint.h>. C23 added
// most of <string.h> to that list. There is no promise of printf, malloc or
// files. Chapter 36 lists the full freestanding subset.
//
// The macro __STDC_HOSTED__ is 1 in a hosted implementation and 0 in a
// freestanding one. gcc and clang select freestanding mode with
// -ffreestanding.
//
// __STDC_VERSION__ tells which standard is in effect:
//
//     199901L  C99        201710L  C17
//     201112L  C11        202311L  C23
//
// C89 does not define it at all.

#include <stdio.h>

int main(void) {
    printf("__STDC_HOSTED__  = %d\n", __STDC_HOSTED__);
    printf("__STDC_VERSION__ = %ldL\n", __STDC_VERSION__);

#if __STDC_VERSION__ >= 202311L
    puts("compiled as C23 or later");
#else
    puts("compiled as an older standard");
#endif
    return 0;
}

// Output:
// __STDC_HOSTED__  = 1
// __STDC_VERSION__ = 202311L
// compiled as C23 or later

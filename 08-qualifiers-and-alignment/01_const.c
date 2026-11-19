// -----------------------------------------------------------------------------
// 01_const.c - a promise not to modify, checked at translation time
//
// Run:  scripts/run.sh 08-qualifiers-and-alignment/01_const.c
// -----------------------------------------------------------------------------
//
// const is a qualifier. An object declared const cannot be assigned to,
// incremented, or passed to a parameter that would allow the modification.
// The attempt is a constraint violation, not undefined behaviour: it fails
// to compile. File 07 is that failure.
//
// Where the const sits changes which thing is constant.
//
//     const int *p    pointer to const int. *p cannot be written.
//                     p can be reseated.
//     int *const p    const pointer to int. p cannot be reseated.
//                     *p can be written.
//     const int *const p
//                     neither can be written.
//
// const does not mean "a constant expression". A const int object is not
// usable as an array length. constexpr, in chapter 6, is the specifier
// that does that. const means the program does not write this object
// through this type.
//
// Casting away const and then writing is undefined if the object was
// defined const. It is defined if the object was not, and the const was
// only on the access path. Don't. The type system is the check; defeating
// it gives you no further check.

#include <stdio.h>

int main(void) {
    int v = 1;
    const int n = 2;

    const int *p = &v;
    int *const fixed = &v;
    const int *const both = &n;

    p = &n;
    *fixed = 3;

    printf("%d %d %d\n", *p, *fixed, *both);
    return 0;
}

// Output:
// 2 3 2

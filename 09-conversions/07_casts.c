// -----------------------------------------------------------------------------
// 07_casts.c - a conversion you ask for
//
// Run:  scripts/run.sh 09-conversions/07_casts.c
// -----------------------------------------------------------------------------
//
// A cast, (type) expression, converts the value to that type. It is how
// you request a conversion the language would not do on its own, and how
// you make an implicit conversion visible at the call site.
//
// The conversions are the ones the previous files describe. A cast does
// not invent a fourth kind of arithmetic. (int)3.9 truncates toward zero.
// (unsigned)-1 is the modular conversion of file 04. (int)(unsigned)-1
// converts back, and two's complement makes that -1 again.
//
// A pointer converts to void * and back to the same pointer type and
// compares equal to the original. That round trip is defined. Converting
// an integer to a pointer, other than the null pointer constant, is
// implementation-defined; this file does not do it.
//
// void * converts to any object pointer type without a cast. The cast
// below is documentation, not a requirement. C++ would require it. The
// cast to unsigned is a requirement: there is no implicit conversion from
// a negative int to unsigned in a context that wants the bits, other than
// the arithmetic conversions, and those come with a warning when they
// happen inside a comparison.

#include <stdio.h>

int main(void) {
    printf("%d\n", (int)3.9);
    printf("%d\n", (int)-3.9);
    printf("%u\n", (unsigned)-1);
    printf("%d\n", (int)(unsigned)-1);

    int x = 6;
    void *vp = &x;
    int *ip = (int *)vp;
    printf("%d\n", *ip);
    return 0;
}

// Output:
// 3
// -3
// 4294967295
// -1
// 6

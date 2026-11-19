// -----------------------------------------------------------------------------
// 09_to_bool.c - zero is false, and everything else is true
//
// Run:  scripts/run.sh 09-conversions/09_to_bool.c
// -----------------------------------------------------------------------------
//
// Any scalar converts to bool. The result is false when the value compares
// equal to 0, and true otherwise. That covers integers, floating values,
// and pointers. A null pointer is false. A NaN is true, because a NaN
// compares unequal to zero just as it compares unequal to everything.
//
// The conversion is what if, while, for, &&, and || perform on their
// conditions. Writing if (p) is the conversion of p to bool. Writing
// if (p != nullptr) is a comparison that then converts to bool. For a
// pointer they agree. For an integer, if (n) is true for every value
// except zero, including negative values.
//
// Assigning a scalar to a bool object does this conversion. The value
// stored is 0 or 1, never the original number. Chapter 4 stored 5 and
// got 1.

#include <math.h>
#include <stdio.h>

int main(void) {
    int x = 1;
    int *p = &x;

    printf("%d %d %d %d\n", (bool)0, (bool)5, (bool)0.0, (bool)-2);
    printf("%d %d %d\n", (bool)nullptr, (bool)p, (bool)(x - 1));
    printf("%d\n", (bool)NAN);
    return 0;
}

// Output:
// 0 1 0 1
// 0 1 0
// 1

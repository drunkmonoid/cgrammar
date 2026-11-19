// -----------------------------------------------------------------------------
// 05_signed_unsigned_compare.c - the comparison people write, and what it does
//
// Run:  scripts/run.sh 09-conversions/05_signed_unsigned_compare.c
// -----------------------------------------------------------------------------
// @flags -Wno-sign-compare
//
// i < u, with i equal to -1 and u equal to 1, is false. The comparison
// converts i to unsigned int first, and every unsigned value is greater
// than or equal to zero, so the converted i is larger than u.
//
// Both compilers diagnose the mixed comparison. This file turns that
// diagnostic off so the result can be printed. The fix is the cast in the
// previous file, chosen for the comparison you actually wanted: compare
// in the signed type when the unsigned value fits, or don't get here with
// a negative value.
//
// The warning is the feature. A build that promotes it to an error, which
// is what scripts/check_all.sh does, will not accept this pattern unless
// the file asks to suppress it, as this one does.

#include <stdio.h>

int main(void) {
    int i = -1;
    unsigned u = 1;
    printf("%d\n", i < u);
    return 0;
}

// Output:
// 0

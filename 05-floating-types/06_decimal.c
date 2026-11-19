// -----------------------------------------------------------------------------
// 06_decimal.c - base-10 floating types
//
// Run:  scripts/run.sh 05-floating-types/06_decimal.c
// -----------------------------------------------------------------------------
// @only gcc clang has no decimal floating types
//
// _Decimal32, _Decimal64, and _Decimal128 are floating types whose
// significand is decimal. 0.1 is exact. Ten copies of 0.1dd add up to
// 1.0dd, which the binary double in file 01 could not do.
//
// The constant suffixes are df, dd, and dl. The sizes on this platform
// are 4, 8, and 16 bytes, the same as the binary types of matching names;
// the encoding is not the same.
//
// clang 21 rejects the types and the suffixes. gcc 15 accepts them. The
// directive above builds this file with gcc only.
//
// printf has length modifiers for these types (H, D, DD). This version of
// glibc does not implement them, so the values are printed by converting
// to double. The conversion can round; the comparison below does not go
// through double, so it is the one that matters.

#include <stdio.h>

int main(void) {
    _Decimal32 a = 1.50df;
    _Decimal64 b = 2.25dd;
    _Decimal128 c = 3.50dl;
    printf("%zu %zu %zu\n", sizeof a, sizeof b, sizeof c);
    printf("%.2f %.2f %.2f\n", (double)a, (double)b, (double)c);

    _Decimal64 tenth = 0.1dd;
    _Decimal64 sum = 0.0dd;
    for (int i = 0; i < 10; i++) {
        sum += tenth;
    }
    printf("%d\n", sum == 1.0dd);
    return 0;
}

// Output:
// 4 8 16
// 1.50 2.25 3.50
// 1

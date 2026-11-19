// -----------------------------------------------------------------------------
// 05_stdint.c - exact widths, and the two types that count in memory
//
// Run:  scripts/run.sh 04-integer-types/05_stdint.c
// -----------------------------------------------------------------------------
//
// <stdint.h> names integer types by the job they do.
//
//     int32_t, uint32_t     exactly N bits, two's complement, no padding.
//                           An implementation may omit a width it cannot
//                           provide. This one provides 8, 16, 32, and 64.
//     int_least32_t         the smallest type with at least that width
//     int_fast16_t          the fastest type with at least that width.
//                           "Fast" is the implementation's choice. Here
//                           int_fast16_t is 8 bytes, not 2.
//     intmax_t              the widest standard integer the library uses
//     intptr_t, uintptr_t   wide enough to hold any object pointer
//
// INT32_C(42) and UINT64_C(1) are constants of the matching type. The
// printf macros in <inttypes.h> (PRId32 and the rest) are the format
// strings for them. A bare %d is wrong once the type might not be int.
//
// size_t, from <stddef.h>, is the unsigned type of sizeof and of a size
// argument. ptrdiff_t is the signed type of a pointer subtraction. Both
// are 64 bits here. SIZE_MAX and PTRDIFF_MAX live in the same headers
// through <stdint.h>.

#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stddef.h>

int main(void) {
    printf("%zu %zu %zu\n", sizeof(int32_t), sizeof(int64_t), sizeof(intmax_t));
    printf("%zu %zu\n", sizeof(int_least32_t), sizeof(int_fast16_t));
    printf("%zu %zu\n", sizeof(size_t), sizeof(ptrdiff_t));

    int32_t n = INT32_C(42);
    printf("%" PRId32 "\n", n);
    printf("%zu\n", sizeof(INT64_C(1)));

    int a[4];
    ptrdiff_t d = &a[3] - &a[0];
    printf("%td\n", d);
    return 0;
}

// Output:
// 4 8 8
// 4 8
// 8 8
// 42
// 8
// 3

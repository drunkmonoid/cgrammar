// -----------------------------------------------------------------------------
// 03_bool.c - a one-bit integer that stores only 0 or 1
//
// Run:  scripts/run.sh 04-integer-types/03_bool.c
// -----------------------------------------------------------------------------
//
// bool is an unsigned integer type. Its only values are 0 and 1, spelled
// false and true. Any scalar converted to bool becomes false when it
// compares equal to zero and true otherwise, so assigning 5 stores 1, and
// assigning a null pointer stores 0.
//
// Before C23 the name was the keyword _Bool, and bool, true, and false were
// macros from <stdbool.h>. The header still exists and still defines those
// macros as the keywords, so old code keeps compiling. New code does not
// need the header.
//
// bool promotes to int (chapter 9). sizeof(bool) is 1 here; the standard
// only requires that it can represent 0 and 1. BOOL_WIDTH, from <limits.h>,
// is the number of value bits: 1.

#include <limits.h>
#include <stdio.h>

int main(void) {
    bool b = 5;
    bool nothing = false;
    int *p = nullptr;

    printf("%d %d %d\n", true, false, b);
    printf("%d %d\n", (bool)2.5, (bool)p);
    printf("%zu %d %d\n", sizeof(bool), BOOL_WIDTH, BOOL_MAX);
    printf("%d\n", nothing == false);

    // The older spelling names the same type.
    _Bool same = true;
    printf("%d\n", same == b);
    return 0;
}

// Output:
// 1 0 1
// 1 0
// 1 1 1
// 1
// 1

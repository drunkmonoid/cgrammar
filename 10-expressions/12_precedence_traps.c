// -----------------------------------------------------------------------------
// 12_precedence_traps.c - the grouping you get when you leave the parentheses out
//
// Run:  scripts/run.sh 10-expressions/12_precedence_traps.c
// -----------------------------------------------------------------------------
// @flags -Wno-parentheses -Wno-shift-op-parentheses
//
// These are the expressions from the previous file, without the
// parentheses that spell the grouping. The values are the same, because
// that is the grouping precedence already chose.
//
//     1 << 2 + 1      is  1 << (2 + 1)      8, not (1 << 2) + 1
//     1 + 2 << 1      is  (1 + 2) << 1      6, not 1 + (2 << 1)
//     5 & 3 == 1      is  5 & (3 == 1)      0, not (5 & 3) == 1
//
// gcc warns that the parentheses are missing. clang warns, and it names
// the shift case separately. The directive on this file turns those
// warnings off so the results can be printed. The previous file is how
// the expressions should be written.

#include <stdio.h>

int main(void) {
    printf("%d\n", 1 << 2 + 1);
    printf("%d\n", 1 + 2 << 1);
    printf("%d\n", 5 & 3 == 1);
    return 0;
}

// Output:
// 8
// 6
// 0

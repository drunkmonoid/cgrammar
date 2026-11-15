// -----------------------------------------------------------------------------
// 08_comments.c - the two comment forms and their traps
//
// Run:  scripts/run.sh 02-translation-and-lexical/08_comments.c
// -----------------------------------------------------------------------------
//
// C has two comments:
//
//     /* ... */     starts at slash-star, ends at the first star-slash.
//                   May span lines. Does NOT nest.
//     // ...        starts at two slashes, ends at the end of the line.
//
// In translation phase 3 each comment is replaced by one space.
//
// Traps:
//
//   1. Block comments do not nest. Commenting out a region that already
//      contains a block comment ends the outer comment early, and the rest
//      of the region is compiled. To disable code, use
//
//          #if 0
//          ...
//          #endif
//
//      which nests properly and copes with comments inside.
//
//   2. Comment markers inside a string literal or a character constant are
//      ordinary characters.
//
//   3. A // comment that ends in a backslash continues on the next line,
//      because lines are spliced (phase 2) before comments are found
//      (phase 3). The next line silently disappears. gcc and clang warn:
//      "multi-line comment". It happens with Windows paths and ASCII art.
//
//   4. `x = y/*p;` begins a comment. See 03_tokens.c.

#include <stdio.h>

int main(void) {
    int total = 0;

    total += 1; /* a block comment after code */
    total += /* a comment in the middle of an expression */ 2;

    /* A block comment
       over several lines. */
    total += 4;

#if 0
    This text is not C at all, and it does not matter: the preprocessor
    skips it. /* A block comment in here does no harm. */
    total += 1000;
#endif

    // Trap 2: these are strings, not comments.
    const char *a = "/* not a comment */";
    const char *b = "// not a comment either";
    printf("%s\n%s\n", a, b);

    // A URL in a string is safe for the same reason.
    printf("%s\n", "https://example.org/");

    printf("total = %d\n", total);
    return 0;
}

// Output:
// /* not a comment */
// // not a comment either
// https://example.org/
// total = 7

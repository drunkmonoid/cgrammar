// -----------------------------------------------------------------------------
// 01_translation_phases.c - the eight phases a source file goes through
//
// Run:  scripts/run.sh 02-translation-and-lexical/01_translation_phases.c
// -----------------------------------------------------------------------------
//
// The standard describes translation as eight phases, applied in order. A
// compiler need not have eight passes, but it must behave as if it did.
//
//   1. Map the bytes of the file to the source character set.
//   2. Delete every backslash that is immediately followed by a newline,
//      joining the two lines ("line splicing").
//   3. Split the text into preprocessing tokens and white space. Each
//      comment becomes one space.
//   4. Run preprocessing directives and expand macros. Each #include file
//      goes through phases 1 to 4 itself.
//   5. Convert characters and escape sequences in character constants and
//      string literals to the execution character set.
//   6. Concatenate adjacent string literals.
//   7. Convert preprocessing tokens to tokens, then parse, check and
//      translate the result. This is "compilation" in the narrow sense.
//   8. Resolve references between translation units and libraries: linking.
//
// The order explains behaviour that otherwise looks arbitrary. Each line
// printed below depends on one phase running before another.

#include <stdio.h>

#define TWICE(x) ((x) + (x))
#define NAME "phase"

int main(void) {
    // Phase 2 before phase 3: the splice happens before tokens exist, so a
    // backslash-newline can sit in the middle of a token.
    int to\
tal = 40 + 2;
    printf("total = %d\n", total);

    // Phase 3 before phase 4: a comment is already a space when macros are
    // expanded, so it separates tokens and never glues them together.
    int a = 3;
    int b = a/**/+/**/a;
    printf("b = %d\n", b);

    // Phase 3 before phase 4, again: macro names inside a string literal are
    // not replaced, because the literal is already one token.
    printf("TWICE(4) is %d\n", TWICE(4));

    // Phase 4 before phase 6: NAME is expanded to a string literal first,
    // and only then are the three adjacent literals joined into one.
    puts("this is " NAME " six");

    // Phase 5 before phase 6: escape sequences are converted in each literal
    // on its own. "\x4" "1" is the character 4 followed by '1', not "\x41".
    const char *s = "\x4" "1";
    printf("first char %d, second char '%c'\n", s[0], s[1]);

    return 0;
}

// Output:
// total = 42
// b = 6
// TWICE(4) is 8
// this is phase six
// first char 4, second char '1'

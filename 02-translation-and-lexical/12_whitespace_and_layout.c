// -----------------------------------------------------------------------------
// 12_whitespace_and_layout.c - where white space matters and where it does not
//
// Run:  scripts/run.sh 02-translation-and-lexical/12_whitespace_and_layout.c
// -----------------------------------------------------------------------------
//
// C is free-form. Between tokens, any amount of white space (spaces, tabs,
// newlines, comments) means the same as one space, and where the tokens
// cannot run together it may be left out entirely. Indentation is for the
// reader; the compiler ignores it.
//
// White space is required only to keep two tokens apart that would
// otherwise be read as one: `int x` (not `intx`), `return 0`, `a - -b`.
//
// It is significant in three places:
//
//   1. Inside string literals and character constants.
//   2. In preprocessing directives. A directive ends at the newline, and in
//      a macro definition the space after the name decides what the macro
//      is:
//
//          #define F(x) ((x) + 1)     function-like macro F
//          #define G (x) ((x) + 1)    object-like macro G, whose replacement
//                                     text is "(x) ((x) + 1)"
//
//   3. After a backslash at the end of a line (see 09_line_splicing.c).
//
// Because indentation means nothing, it can mislead. The second statement
// under the `if` below is not controlled by it.

#include <stdio.h>

#define F(x) ((x) + 1)

// The same function twice: laid out, and on one line.
static int max_readable(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

static int max_dense(int a,int b){if(a>b){return a;}return b;}

int main(void) {
    printf("%d %d\n", max_readable(3, 8), max_dense(3, 8));
    printf("F(1) = %d\n", F(1));

    int checked = 0;
    int ready = 0;

    // Misleading layout: only the first statement belongs to the if.
    // Braces remove the doubt. (-Wmisleading-indentation catches this when
    // the two lines are aligned; here they are kept apart to compile clean.)
    if (ready)
        checked = 1;

    checked += 10;

    printf("checked = %d\n", checked);
    return 0;
}

// Output:
// 8 8
// F(1) = 2
// checked = 10

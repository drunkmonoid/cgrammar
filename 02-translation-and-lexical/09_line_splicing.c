// -----------------------------------------------------------------------------
// 09_line_splicing.c - backslash-newline joins two lines into one
//
// Run:  scripts/run.sh 02-translation-and-lexical/09_line_splicing.c
// -----------------------------------------------------------------------------
//
// In phase 2, a backslash immediately followed by a newline is deleted,
// together with the newline. The compiler never sees either of them.
//
// Its main use is in macro definitions. A directive ends at the end of its
// line, so a long macro is written over several spliced lines.
//
// Because splicing happens before tokenisation, it works anywhere, even in
// the middle of a string or a name. Inside a string the next line's leading
// spaces become part of the string, so prefer adjacent string literals: the
// compiler joins them in phase 6 and indentation stays out of the text.
//
// The backslash must be the last character on the line. A space after it is
// easy to miss; gcc and clang accept that and warn, other compilers may not
// splice at all.
//
// A source file must not end in a backslash, and a non-empty file must end
// in a newline.

#include <stdio.h>

// A macro over three physical lines. It is one logical line.
#define PRINT_SUM(a, b)                     \
    printf("%d + %d = %d\n", (a), (b),      \
           (a) + (b))

int main(void) {
    PRINT_SUM(2, 3);

    // A string continued with a splice. The second line starts in column
    // one on purpose: any indentation would end up inside the string.
    const char *spliced = "one \
two";
    puts(spliced);

    // The better way to break a long string.
    const char *joined = "one "
                         "two";
    puts(joined);

    // A splice may even cut a number in half.
    int n = 12\
34;
    printf("n = %d\n", n);
    return 0;
}

// Output:
// 2 + 3 = 5
// one two
// one two
// n = 1234

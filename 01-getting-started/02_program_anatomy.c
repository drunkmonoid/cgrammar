// -----------------------------------------------------------------------------
// 02_program_anatomy.c - the parts of a source file and the order they need
//
// Run:  scripts/run.sh 01-getting-started/02_program_anatomy.c
// -----------------------------------------------------------------------------
//
// A source file is a sequence of declarations. There are no statements at
// the top level: code that runs lives inside a function.
//
// The compiler reads top to bottom, once. A name must be declared before
// the line that uses it. That is why headers come first, and why `square`
// is declared before main although it is defined after it.

// 1. Preprocessor directives. #include pastes a header's text here.
#include <stdio.h>

// 2. A macro: the preprocessor replaces LIMIT with 5 before compilation.
#define LIMIT 5

// 3. A function declaration (a prototype): name, parameters, return type.
//    It promises that a definition exists somewhere.
int square(int n);

// 4. An object defined at file scope. It lives for the whole run.
int calls = 0;

// 5. The function where execution starts.
int main(void) {
    // Declarations and statements may be mixed inside a block.
    int total = 0;

    for (int i = 1; i <= LIMIT; i++) {
        total += square(i);
    }

    printf("sum of squares up to %d: %d\n", LIMIT, total);
    printf("square was called %d times\n", calls);
    return 0;
}

// 6. The definition promised at step 3.
int square(int n) {
    calls++;
    return n * n;
}

// Output:
// sum of squares up to 5: 55
// square was called 5 times

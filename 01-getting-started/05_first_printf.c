// -----------------------------------------------------------------------------
// 05_first_printf.c - first steps with printf and puts
//
// Run:  scripts/run.sh 01-getting-started/05_first_printf.c
// -----------------------------------------------------------------------------
//
// printf writes its first argument, the format string, to standard output.
// Each `%` conversion in the format consumes one of the following arguments
// and prints it. The conversion must match the argument's type:
//
//     %d   int                    %s   string (char *)
//     %u   unsigned int           %c   one character
//     %f   double                 %%   a literal percent sign
//     %zu  size_t (what sizeof yields)
//
// A mismatch (`%d` with a double, too few arguments) is undefined behaviour.
// The compiler cannot reject it, because printf is an ordinary function, but
// -Wall checks format strings and warns. Chapter 28 covers every conversion.
//
// Nothing ends the line for you: write `\n` where you want a new line.
// puts(s) prints s followed by a newline, with no conversions.

#include <stdio.h>

int main(void) {
    int count = 3;
    double ratio = 2.5;
    char grade = 'A';
    const char *name = "Ada";

    printf("count = %d\n", count);
    printf("ratio = %f\n", ratio);            // six digits after the point
    printf("ratio = %.2f\n", ratio);          // precision of two
    printf("grade = %c, name = %s\n", grade, name);
    printf("[%5d] [%-5d] [%05d]\n", 42, 42, 42);  // width, left-justify, zero-pad
    printf("100%% done\n");
    printf("an int takes %zu bytes here\n", sizeof(int));

    // Several calls can build one line.
    printf("one ");
    printf("two ");
    printf("three\n");

    // printf returns the number of characters it wrote.
    int written = printf("hello\n");
    printf("the previous call wrote %d characters\n", written);

    puts("puts adds the newline itself");
    return 0;
}

// Output:
// count = 3
// ratio = 2.500000
// ratio = 2.50
// grade = A, name = Ada
// [   42] [42   ] [00042]
// 100% done
// an int takes 4 bytes here
// one two three
// hello
// the previous call wrote 6 characters
// puts adds the newline itself

// -----------------------------------------------------------------------------
// 06_first_input.c - reading a line and a number from standard input
//
// Run:  printf 'Ada\n36\n' | scripts/run.sh 01-getting-started/06_first_input.c
// -----------------------------------------------------------------------------
// @stdin Ada Lovelace\n36\n
//
// Input can fail: the user may type letters where a number is expected, or
// the input may simply end. Every input function reports this through its
// return value, and a program that ignores it reads garbage.
//
//     fgets(buf, size, stdin)   reads at most size - 1 characters of a line,
//                               keeps the '\n', returns a null pointer at
//                               end of input.
//     scanf("%d", &n)           returns the number of conversions that
//                               succeeded: 1 here, 0 if the text is not a
//                               number, EOF at end of input.
//
// scanf needs the address of the variable (&n), because C passes arguments
// by value and the function must write to the caller's object.
//
// Never read a string with scanf("%s") or with gets: neither knows the size
// of the buffer. gets was removed from the language in C11.

#include <stdio.h>
#include <string.h>

int main(void) {
    char name[64];
    int age;

    printf("name? ");
    if (fgets(name, sizeof name, stdin) == nullptr) {
        puts("\nno name given");
        return 1;
    }
    // Drop the newline fgets kept. strcspn gives the index of the first
    // '\n', or the length of the string if there is none.
    name[strcspn(name, "\n")] = '\0';

    printf("age? ");
    if (scanf("%d", &age) != 1) {
        puts("\nthat is not a number");
        return 1;
    }

    printf("\n%s will be %d next year\n", name, age + 1);
    return 0;
}

// Output:
// name? age?
// Ada Lovelace will be 37 next year

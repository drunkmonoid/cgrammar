// -----------------------------------------------------------------------------
// 01_hello_world.c - the smallest useful C program
//
// Run:  scripts/run.sh 01-getting-started/01_hello_world.c
// -----------------------------------------------------------------------------
//
// By hand:
//
//     gcc -std=c23 -Wall -Wextra -pedantic 01_hello_world.c -o hello
//     ./hello
//
// Three things are needed to print a line:
//   1. #include <stdio.h> brings in the declaration of puts.
//   2. Execution starts in the function called main.
//   3. main returns an int to whoever started the program; 0 means success.

#include <stdio.h>

int main(void) {
    puts("Hello, world!");
    return 0;
}

// Output:
// Hello, world!

// -----------------------------------------------------------------------------
// 04_exit_status.c - what main returns, and who reads it
//
// Run:  scripts/run.sh 01-getting-started/04_exit_status.c; echo "status: $?"
// -----------------------------------------------------------------------------
// @exit 3
//
// The value main returns goes to the environment that started the program.
// In a shell it is `$?`; in a script it decides whether `&&` continues.
//
// The standard defines the meaning of three values only:
//
//     0             success
//     EXIT_SUCCESS  success (from <stdlib.h>, normally 0)
//     EXIT_FAILURE  failure (from <stdlib.h>, normally 1)
//
// Any other value is implementation-defined. On POSIX systems the low eight
// bits reach the parent, so `return 256;` looks like success. Stay within
// 0 to 125: shells use 126 and above for their own reports.
//
// Two rules that are special to main:
//   - Reaching the closing brace of main without a return is the same as
//     `return 0;`. That holds for main only. In any other function with a
//     non-void return type, using the missing value is undefined behaviour.
//   - `return n;` in main is equivalent to calling exit(n) (chapter 31).
//
// This program returns 3 on purpose; the check script expects it.

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    printf("EXIT_SUCCESS = %d\n", EXIT_SUCCESS);
    printf("EXIT_FAILURE = %d\n", EXIT_FAILURE);
    puts("returning 3");
    return 3;
}

// Output:
// EXIT_SUCCESS = 0
// EXIT_FAILURE = 1
// returning 3

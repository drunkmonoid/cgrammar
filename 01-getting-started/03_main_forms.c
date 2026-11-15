// -----------------------------------------------------------------------------
// 03_main_forms.c - the two forms of main the standard defines
//
// Run:  scripts/run.sh 01-getting-started/03_main_forms.c one two 3
// -----------------------------------------------------------------------------
// @args one two 3
//
// A hosted program defines main in one of two ways:
//
//     int main(void)                      takes nothing
//     int main(int argc, char *argv[])    receives the command line
//
// The parameter names are a convention; any names work. `char **argv` is the
// same type as `char *argv[]`. An implementation may accept other forms
// (a third `envp` parameter is common), but those are not portable.
//
// What the standard promises about the second form:
//   - argc is never negative.
//   - argv[argc] is a null pointer.
//   - If argc > 0, argv[0] is the program name, or an empty string if the
//     name is not available.
//   - argv[1] to argv[argc - 1] are the arguments, as strings.
//   - The program may modify argc, argv and the strings.
//
// Arguments are always strings. "3" below is the two characters '3' and
// '\0', not the number three; chapter 32 converts strings to numbers.

#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("argc = %d\n", argc);

    // Start at 1: argv[0] is the path used to start the program, which
    // changes from one machine to the next.
    for (int i = 1; i < argc; i++) {
        printf("argv[%d] = \"%s\"\n", i, argv[i]);
    }

    if (argv[argc] == nullptr) {
        puts("argv[argc] is a null pointer");
    }
    return 0;
}

// Output:
// argc = 4
// argv[1] = "one"
// argv[2] = "two"
// argv[3] = "3"
// argv[argc] is a null pointer

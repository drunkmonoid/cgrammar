// -----------------------------------------------------------------------------
// 09_undeclared_function_error.c - a program that must NOT compile
//
// Run:  scripts/run.sh 01-getting-started/09_undeclared_function_error.c
// -----------------------------------------------------------------------------
// @build fail
//
// Every function must be declared before it is called. Here <stdio.h> is
// missing, so the compiler has never heard of puts.
//
// C89 allowed this: an unknown function was silently assumed to return int
// and to take whatever it was given. C99 removed that rule. Compilers went
// on accepting such code with a warning for twenty-five years; gcc 14 and
// clang 16 made it an error.
//
// The message from gcc:
//
//     error: implicit declaration of function 'puts'
//     note: include '<stdio.h>' or provide a declaration of 'puts'

int main(void) {
    puts("this line is never printed");
    return 0;
}

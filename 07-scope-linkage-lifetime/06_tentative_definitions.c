// -----------------------------------------------------------------------------
// 06_tentative_definitions.c - a file-scope object may be defined in pieces
//
// Run:  scripts/run.sh 07-scope-linkage-lifetime/06_tentative_definitions.c
// -----------------------------------------------------------------------------
//
// A file-scope declaration of an object, with no initializer and with
// external or internal linkage, is a tentative definition. Any number of
// them may name the same object. At the end of the translation unit, if
// no declaration of that object had an initializer, the tentative
// definitions become one definition with an initializer of zero.
//
// n below is declared three times. The third has an initializer, so that
// one is the definition and the value is 4. m is only tentative, so it
// becomes a zero-initialized definition.
//
// This is a property of one translation unit. Across translation units,
// two definitions with initializers are two definitions, and the program
// is ill-formed. The directory next to this file is that rule, shown by
// linking.

#include <stdio.h>

int n;
int n;
int n = 4;

int m;
int m;

int main(void) {
    printf("%d %d\n", n, m);
    return 0;
}

// Output:
// 4 0

// -----------------------------------------------------------------------------
// 06_identifiers.c - what a name may look like
//
// Run:  scripts/run.sh 02-translation-and-lexical/06_identifiers.c
// -----------------------------------------------------------------------------
//
// An identifier names an object, a function, a type, a struct member, a
// label or a macro. The rules:
//
//   - It starts with a letter or an underscore, and continues with letters,
//     digits and underscores.
//   - It cannot be a keyword.
//   - Case is significant: `count`, `Count` and `COUNT` are three names.
//   - There is no length limit, but an implementation only has to tell
//     apart the first 63 characters of an internal name and the first 31 of
//     an external one (a name the linker sees). gcc and clang treat every
//     character as significant.
//
// "Letter" is wider than A to Z. C23 follows Unicode: an identifier starts
// with a character that has the XID_Start property and continues with
// XID_Continue characters. Accented letters, Greek and CJK are allowed;
// emoji and punctuation are not. A character may be written directly or as
// a universal character name (é), and both spell the same identifier.
//
// Conventions, not rules:
//   - snake_case for objects and functions, UPPER_CASE for macros.
//   - A trailing _t is used by the library and by POSIX for type names.

#include <stdio.h>

int main(void) {
    int count = 1;
    int Count = 2;
    int COUNT = 3;
    printf("count, Count, COUNT = %d, %d, %d\n", count, Count, COUNT);

    // An underscore is a letter for this purpose. Leading underscores are
    // best avoided, though: many such names are reserved (see 07).
    int total_items_2 = 10;
    printf("total_items_2 = %d\n", total_items_2);

    // Unicode identifiers.
    double π = 3.14159;
    int größe = 42;
    printf("π = %.5f, größe = %d\n", π, größe);

    // The same identifier, spelled with a universal character name.
    int café = 7;
    printf("café = %d\n", café);
    return 0;
}

// Output:
// count, Count, COUNT = 1, 2, 3
// total_items_2 = 10
// π = 3.14159, größe = 42
// café = 7

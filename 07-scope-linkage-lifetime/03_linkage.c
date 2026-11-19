// -----------------------------------------------------------------------------
// 03_linkage.c - when two declarations name one object
//
// Run:  scripts/run.sh 07-scope-linkage-lifetime/03_linkage.c
// -----------------------------------------------------------------------------
//
// Linkage is what makes two declarations, possibly in different translation
// units, refer to the same object or function.
//
//   external    one definition for the whole program. This is the default
//               for a function, and for a file-scope object with no
//               storage-class specifier.
//   internal    one definition for this translation unit. static at file
//               scope gives it. Another file may use the same name for
//               something else.
//   none        the declaration is unique. Parameters, block-scope objects
//               without extern, and typedef names have no linkage. Two of
//               them are two objects even when the spelling matches.
//
// extern on a block-scope declaration does not define the object. It
// refers to the one the linkage already names. The file
// 08_external_linkage shows that reference crossing from one file into
// another. static at block scope does not mean internal linkage; it means
// static storage duration, which is the next file.

#include <stdio.h>

static int internal_value = 2;
int external_value = 40;

static int helper(void) {
    return internal_value;
}

int main(void) {
    extern int external_value;
    int none = 0;

    printf("%d %d %d\n", helper(), external_value, none);
    return 0;
}

// Output:
// 2 40 0

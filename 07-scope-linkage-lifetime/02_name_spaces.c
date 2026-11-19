// -----------------------------------------------------------------------------
// 02_name_spaces.c - the same spelling can be four different names
//
// Run:  scripts/run.sh 07-scope-linkage-lifetime/02_name_spaces.c
// -----------------------------------------------------------------------------
//
// C keeps four name spaces, and a lookup uses only one of them. The same
// spelling in two name spaces is two names, not a clash and not a shadow.
//
//   labels                 the operand of goto, and the name before a :
//   tags                   the name after struct, union, or enum
//   members                the name after . or ->. Each struct or union
//                          has its own member name space, so two structs
//                          may both have a member called x.
//   ordinary identifiers   objects, functions, typedef names, enumeration
//                          constants
//
// The program below uses one spelling for a tag, a member, an object, and
// a label. Each occurrence is looked up in a different name space, which
// is why it compiles. It is legal. It is not a kindness to the reader.

#include <stdio.h>

struct box {
    int box;
};

struct other {
    double box;
};

int main(void) {
    struct box box;
    box.box = 1;

    struct other other;
    other.box = 2.5;

    printf("%d %.1f\n", box.box, other.box);
    goto box;
box:
    puts("label");
    return 0;
}

// Output:
// 1 2.5
// label

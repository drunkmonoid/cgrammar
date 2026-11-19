// -----------------------------------------------------------------------------
// 01_scopes.c - where a name is visible
//
// Run:  scripts/run.sh 07-scope-linkage-lifetime/01_scopes.c
// -----------------------------------------------------------------------------
//
// A name is visible in one of four scopes.
//
//   file         from its declaration to the end of the translation unit.
//                This is where functions and objects with linkage live.
//   block        from its declaration to the end of the enclosing block.
//                A nested declaration of the same name hides the outer one
//                until the block ends. The for-loop declarator is in the
//                scope of the loop, and nowhere after it.
//   function prototype
//                the parameter names in a declaration that is not a
//                definition. They disappear at the end of the prototype,
//                so they do not clash with a later file-scope name, and
//                they are not visible in any function body.
//   function     labels only. A label is visible throughout the function
//                it appears in, including in blocks that contain the goto,
//                and it is not visible in any other function.
//
// The parameter of a function definition is in block scope, the block
// being the function body. That is a different rule from the prototype.

#include <stdio.h>

int file_var = 1;
static int hidden = 2;

int first(int n);

int n = 5;

int first(int n) {
    return n + 1;
}

int main(void) {
    int file_var = 3;
    printf("%d %d\n", file_var, hidden);
    {
        int file_var = 4;
        printf("%d\n", file_var);
    }
    printf("%d\n", file_var);

    for (int i = 0; i < 3; i++) {
        printf("%d", i);
    }
    printf("\n");

    printf("%d\n", first(n));

    if (n == 5) {
        goto done;
    }
    puts("skipped");
done:
    puts("done");
    return 0;
}

// Output:
// 3 2
// 4
// 3
// 012
// 6
// done

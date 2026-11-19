// -----------------------------------------------------------------------------
// 06_typeof.c - name the type an expression already has
//
// Run:  scripts/run.sh 06-declarations/06_typeof.c
// -----------------------------------------------------------------------------
//
// typeof (expression) is the type of that expression, qualifiers included
// when the expression is an lvalue. typeof (type-name) is that type.
// Parentheses are required.
//
// typeof_unqual is the same and then strips qualifiers at the top level,
// including _Atomic and restrict. What it points at is left alone:
// typeof_unqual of a const int * is still a pointer to const int. Only
// the pointer itself would have been const, and it was not.
//
// Unlike auto, typeof does not decay an array. typeof of an array of 4
// int is an array of 4 int, and a variable of that type has the same size
// as the original. typeof of an expression that is not an lvalue, such as
// x + 1, has the unqualified type of the value. The const lived on the
// object, and the addition has already read it.
//
// The older GNU spelling is __typeof__. It is not standard C. typeof and
// typeof_unqual are.

#include <stdio.h>

int main(void) {
    int a[4];
    typeof(a) copy;

    const int x = 1;
    typeof(x) still_const = 2;
    typeof_unqual(x) plain = 3;
    plain = 4;

    typeof(x + 1) value = 5;

    const int *cp = &x;
    typeof_unqual(cp) still_points_const = cp;

    printf("%zu %zu\n", sizeof a, sizeof copy);
    printf("%d %d %d\n", still_const, plain, value);
    printf("%d\n", *still_points_const);
    return 0;
}

// Output:
// 16 16
// 2 4 5
// 1

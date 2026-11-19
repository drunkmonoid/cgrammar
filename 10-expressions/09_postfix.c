// -----------------------------------------------------------------------------
// 09_postfix.c - subscript, member, and call
//
// Run:  scripts/run.sh 10-expressions/09_postfix.c
// -----------------------------------------------------------------------------
//
// [] . -> and the call () are postfix operators. They bind tighter than
// any prefix operator, which is why *a[i] is *(a[i]) and not (*a)[i].
//
// The subscript operator is defined as addition and dereference:
//
//     a[i]    means    *(a + i)
//
// Addition of a pointer and an integer is commutative, so i[a] means the
// same thing. Both forms below read the same element. The second is not
// a form to write. It is evidence of what the operator actually is.
//
// . names a member of a struct or union value. -> names a member of the
// object a pointer points at. p->m means (*p).m. Structures themselves
// are chapter 18; the operators are here because the precedence table
// would be missing them.
//
// The call operator calls the function a function pointer points at. A
// function designator decays to that pointer (chapter 9), so f(6) and
// (*f)(6) call the same function.

#include <stdio.h>

struct pair {
    int x;
    int y;
};

int successor(int n) {
    return n + 1;
}

int main(void) {
    int a[] = {10, 20, 30};
    printf("%d %d\n", a[2], 2[a]);

    struct pair value = {1, 2};
    struct pair *p = &value;
    printf("%d %d\n", value.y, p->x);

    printf("%d %d\n", successor(6), (*successor)(6));
    return 0;
}

// Output:
// 30 30
// 2 1
// 7 7

// -----------------------------------------------------------------------------
// 07_boolean_and_nullptr.c - the three constants C23 added as keywords
//
// Run:  scripts/run.sh 03-constants-and-literals/07_boolean_and_nullptr.c
// -----------------------------------------------------------------------------
//
// true and false are predefined constants of type bool. They are not macros.
// true converts to the int 1, false to the int 0, which is all a bool can
// hold: storing any other value into a bool yields true. Chapter 4 says
// what the type itself does.
//
// nullptr is a constant of type nullptr_t. It converts to any pointer type,
// and to bool (as false). It compares equal to a null pointer and to the
// integer 0, because 0 is still a null pointer constant. It is not itself
// an int, and it is not a macro the way NULL is.
//
// NULL, from <stddef.h>, is an implementation-defined null pointer constant,
// typically 0 or (void *)0. nullptr has one type everywhere, which is the
// reason to prefer it. Both still compare equal.

#include <stddef.h>
#include <stdio.h>

int main(void) {
    printf("%d %d %zu\n", true, false, sizeof(true));

    bool b = 5;
    printf("%d\n", b);

    int *p = nullptr;
    nullptr_t n = nullptr;
    printf("%d %d %d\n", p == nullptr, p == 0, nullptr == NULL);
    printf("%zu %zu\n", sizeof n, sizeof(nullptr));
    printf("%d\n", (bool)nullptr);
    return 0;
}

// Output:
// 1 0 1
// 1
// 1 1 1
// 8 8
// 0

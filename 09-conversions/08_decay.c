// -----------------------------------------------------------------------------
// 08_decay.c - lvalue conversion, and the two decays
//
// Run:  scripts/run.sh 09-conversions/08_decay.c
// -----------------------------------------------------------------------------
//
// An lvalue is an expression that designates an object. When an lvalue of
// an arithmetic type is used for its value, it is converted to that value.
// The object is read. This is lvalue conversion, and it drops qualifiers:
// a const int object yields an int value.
//
// Two further conversions happen in most expression contexts.
//
//   An array expression becomes a pointer to its first element.
//   A function designator becomes a pointer to the function.
//
// That is why an array can be passed where a pointer is expected, and why
// f and &f both initialize a function pointer. The decays do not happen
// when the array is the operand of sizeof, alignof, typeof, or unary &,
// or a string literal used to initialize an array. sizeof a is the whole
// array. sizeof p, after the decay has already happened, is the pointer.
//
// &a has type "pointer to array of 4 int". It does not decay first.
// sizeof of that pointer is the size of a pointer, not the size of the
// array.

#include <stdio.h>

void greet(int n) {
    printf("greet %d\n", n);
}

int main(void) {
    const int x = 3;
    printf("%d\n", x + 1);

    int a[4] = {1, 2, 3, 4};
    int *p = a;
    printf("%zu %zu %d\n", sizeof a, sizeof p, p[2]);
    printf("%zu\n", sizeof &a);

    void (*fp)(int) = greet;
    void (*fq)(int) = &greet;
    fp(4);
    fq(5);
    return 0;
}

// Output:
// 4
// 16 8 3
// 8
// greet 4
// greet 5

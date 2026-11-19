// -----------------------------------------------------------------------------
// 01_integer_promotions.c - narrow integers become int before the arithmetic
//
// Run:  scripts/run.sh 09-conversions/01_integer_promotions.c
// -----------------------------------------------------------------------------
//
// A value of a type narrower than int is converted to int, or to unsigned
// int if int cannot hold every value of the original type, before it is
// used in an expression. These are the integer promotions. They apply to
// char, signed char, unsigned char, short, unsigned short, and bool, and
// to bit-fields of those widths. They do not apply to _BitInt (chapter 4).
//
// On this platform int is 32 bits, so it can hold every unsigned short.
// unsigned short therefore promotes to int, not to unsigned int.
// 65535 + 1 is 65536. It does not wrap at 16 bits. The wrap would happen
// only if the result were stored back into an unsigned short.
//
// The same promotion is why two shorts can add up to a value no short can
// hold, and the addition is defined: it happens in int. 20000 + 20000 is
// 40000, which would be undefined overflow if short arithmetic existed.
//
// sizeof of the promoted value is sizeof(int). sizeof of the object is
// not. Unary + is the cheapest way to ask for the promotion and nothing
// else.

#include <stdio.h>

int main(void) {
    char c = 1;
    short s = 1;
    bool b = true;
    unsigned short us = 65535;

    printf("%zu %zu %zu %zu\n", sizeof(+c), sizeof(+s), sizeof(+b), sizeof(+us));
    printf("%d\n", us + 1);

    short a = 20000;
    short d = 20000;
    printf("%d %zu\n", a + d, sizeof(a + d));

    unsigned char uc = 200;
    printf("%d\n", uc + uc);
    return 0;
}

// Output:
// 4 4 4 4
// 65536
// 40000 4
// 400

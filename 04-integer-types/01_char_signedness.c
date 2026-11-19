// -----------------------------------------------------------------------------
// 01_char_signedness.c - char is a distinct type, and it may be signed
//
// Run:  scripts/run.sh 04-integer-types/01_char_signedness.c
// -----------------------------------------------------------------------------
//
// char, signed char, and unsigned char are three types. char has the same
// representation and range as one of the other two, and which one is up to
// the implementation. It is not a synonym: a pointer to char is not a
// pointer to signed char.
//
// On x86-64 Linux, char is signed. CHAR_MIN is -128, the same as SCHAR_MIN.
// A value from 128 to 255 does not fit. Converting 200 to char yields -56,
// because the low eight bits of 200 are kept and then read as a signed
// value. unsigned char can hold 200, and it is the type to use for a byte.
//
// The plain char used for letters is fine either way: the execution
// character set gives every letter a positive value, so 'A' is never
// negative. The trouble starts with arbitrary bytes.
//
// CHAR_BIT is the number of bits in a char. It is at least 8, and it is 8
// here, which is why sizeof measures bytes and bytes are octets.

#include <limits.h>
#include <stdio.h>

int main(void) {
    printf("%d %d %d\n", CHAR_BIT, CHAR_MIN, SCHAR_MIN);
    printf("%d\n", UCHAR_MAX);

    int wide = 200;
    char narrowed = (char)wide;
    unsigned char byte = 200;
    printf("%d %d\n", (int)narrowed, (int)byte);

    // A letter is positive whichever signedness char has.
    printf("%d\n", 'A' > 0);
    return 0;
}

// Output:
// 8 -128 -128
// 255
// -56 200
// 1

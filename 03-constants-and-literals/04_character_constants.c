// -----------------------------------------------------------------------------
// 04_character_constants.c - the type and value of a character constant
//
// Run:  scripts/run.sh 03-constants-and-literals/04_character_constants.c
// -----------------------------------------------------------------------------
//
// A character constant is not a string, and in C it is not a char either.
// An unprefixed character constant has type int. 'A' and "A" are different
// tokens: the first is an int, the second is an array of two chars.
//
// The value is the numeric code of that character in the execution
// character set. The codes of '0' through '9' are contiguous and increasing,
// and the letters are positive. This toolchain uses ASCII, so 'A' is 65.
// Nothing in the standard says it is 65 on every machine; EBCDIC is still
// allowed. The recorded output is x86-64 Linux.
//
// A prefix changes the type:
//
//     u8'A'   unsigned char     one UTF-8 code unit (C23)
//     u'A'    char16_t
//     U'A'    char32_t
//     L'A'    wchar_t
//
// u8'é' is a constraint violation: é is two UTF-8 code units, and a u8
// character constant holds one. The string u8"é" is the way to write it
// (next files).
//
// A constant with more than one character, such as 'ab', has type int and
// an implementation-defined value. gcc and clang both warn about it, and
// with -Werror this repository rejects it. There is no portable use for it.

#include <stdio.h>

int main(void) {
    printf("%d %d\n", 'A', '0');
    printf("%d\n", '7' - '0');

    printf("%zu %zu %zu %zu %zu\n",
           sizeof 'A', sizeof u8'A', sizeof u'A', sizeof U'A', sizeof L'A');
    printf("%d\n", u8'A');
    return 0;
}

// Output:
// 65 48
// 7
// 4 1 2 4 4
// 65

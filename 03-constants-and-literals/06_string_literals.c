// -----------------------------------------------------------------------------
// 06_string_literals.c - arrays of characters, joined in phase 6
//
// Run:  scripts/run.sh 03-constants-and-literals/06_string_literals.c
// -----------------------------------------------------------------------------
//
// A string literal has type "array of n char", where n counts the terminating
// null. "ab" has three elements. The array is not const in the type system,
// but modifying it is undefined behaviour. Point a const char * at it.
//
// A prefix changes the element type:
//
//     u8"ab"   char8_t, UTF-8, including the null
//     u"ab"    char16_t
//     U"ab"    char32_t
//     L"ab"    wchar_t
//
// On this platform char16_t is 2 bytes, and both char32_t and wchar_t are 4.
// sizeof u"ab" is therefore 6, and sizeof L"ab" is 12.
//
// Adjacent string literals are concatenated in translation phase 6, after
// escapes have been converted. An ordinary literal may sit beside a
// prefixed one, and the result takes the prefix. u8 concatenates with
// ordinary and with u8. Mixing u, U, and L with each other, or any of them
// with u8, is a constraint violation.
//
// The null is a character like any other. "a\0b" has four elements; strlen
// would stop at the first null, sizeof does not.

#include <stdio.h>
#include <uchar.h>
#include <wchar.h>

int main(void) {
    const char *hello = "hel" "lo";
    printf("%s\n", hello);

    printf("%zu %zu %zu %zu %zu\n",
           sizeof "ab", sizeof u8"ab", sizeof u"ab", sizeof U"ab", sizeof L"ab");

    char8_t mixed[] = u8"hi" "!";
    printf("%s %zu\n", (const char *)mixed, sizeof mixed);

    char16_t u16[] = u"ab" "c";
    wchar_t wide[] = L"ab" "c";
    printf("%zu %d\n", sizeof u16, u16[2] == u'c');
    printf("%zu %d\n", sizeof wide, wide[0] == L'a');

    const char embedded[] = "a\0b";
    printf("%zu %c %d\n", sizeof embedded, embedded[0], embedded[2]);
    return 0;
}

// Output:
// hello
// 3 3 6 12 12
// hi! 4
// 8 1
// 16 1
// 4 a 98

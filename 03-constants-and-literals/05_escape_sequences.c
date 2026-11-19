// -----------------------------------------------------------------------------
// 05_escape_sequences.c - naming characters that have no glyph, or the wrong one
//
// Run:  scripts/run.sh 03-constants-and-literals/05_escape_sequences.c
// -----------------------------------------------------------------------------
//
// An escape sequence inside a character constant or a string literal is
// replaced, in translation phase 5, by one execution character.
//
//     \a  alert      \b  backspace   \f  form feed    \n  newline
//     \r  return     \t  tab         \v  vertical tab
//     \\  backslash  \'  quote       \"  double quote \?  question mark
//
// \? exists so that ??=, which used to be a trigraph, can be written
// without being one. Trigraphs are gone in C23 (chapter 2); the escape
// remains.
//
// A number can name the character directly:
//
//     \101     octal, up to three digits. \0 is the null character.
//     \x41     hexadecimal, as many digits as you write. It does not stop
//              at two: \x41F is one character, not 'A' followed by F.
//     \u00e9   a universal character name, four hex digits.
//     \U000000e9  the same, eight hex digits.
//
// A universal name in a ordinary string becomes the execution encoding of
// that Unicode scalar. This toolchain encodes it as UTF-8, so é is the two
// bytes C3 A9. In a u8 string the same encoding is required, not merely
// what this machine happens to use.

#include <stdio.h>
#include <uchar.h>

int main(void) {
    printf("%d %d %d %d %d\n", '\n', '\t', '\0', '\\', '\'');
    printf("%d %d %d\n", '\x41', '\101', '\?');

    // \x consumes every following hex digit. Split the literal, or the F
    // becomes part of the escape.
    printf("%d %d\n", "\x41" "F"[0], "\x41" "F"[1]);

    const char *word = "caf\u00e9";
    printf("%u %u\n", (unsigned char)word[3], (unsigned char)word[4]);

    char8_t e[] = u8"\u00e9";
    printf("%zu %u %u\n", sizeof e, e[0], e[1]);
    return 0;
}

// Output:
// 10 9 0 92 39
// 65 65 63
// 65 70
// 195 169
// 3 195 169

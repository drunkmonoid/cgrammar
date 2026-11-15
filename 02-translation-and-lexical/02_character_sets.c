// -----------------------------------------------------------------------------
// 02_character_sets.c - source and execution character sets
//
// Run:  scripts/run.sh 02-translation-and-lexical/02_character_sets.c
// -----------------------------------------------------------------------------
//
// Two character sets are involved: the one the source file is written in,
// and the one the running program uses. They can differ (think of a cross
// compiler), and phase 5 converts from the first to the second.
//
// Both contain the basic character set:
//
//     A-Z  a-z  0-9
//     ! " # % & ' ( ) * + , - . / : ; < = > ? [ \ ] ^ _ { | } ~
//     @ $ `                (added to the basic set in C23)
//     space, horizontal tab, vertical tab, form feed, and a line ending
//
// The execution set also has the null character, alert, backspace and
// carriage return.
//
// What the standard guarantees about the values:
//   - Every basic character fits in one byte and is non-negative as a char.
//   - The null character has all bits zero.
//   - '0' to '9' are consecutive and increasing, so c - '0' is a digit's
//     value.
//   - Letters are NOT promised to be consecutive. They are in ASCII; they
//     are not in EBCDIC, where 'i' + 1 is not 'j'. Use <ctype.h>.
//
// Everything else is an extended character. Source files today are almost
// always UTF-8, and gcc and clang use UTF-8 for the execution set too, so a
// non-ASCII character in a string literal becomes several bytes.

#include <stdio.h>
#include <string.h>

int main(void) {
    // Digits are consecutive on every implementation.
    char c = '7';
    printf("'%c' has the value %d\n", c, c - '0');

    // The numeric values below are ASCII. That is true nearly everywhere,
    // but the standard does not require it.
    printf("'A' = %d, 'a' = %d, '0' = %d, ' ' = %d\n", 'A', 'a', '0', ' ');
    printf("'\\0' = %d\n", '\0');

    // The three characters C23 added to the basic set.
    printf("C23 additions: %c %c %c\n", '@', '$', '`');

    // One character on screen, two bytes in the execution character set.
    const char *word = "é";
    printf("\"%s\" is %zu bytes long\n", word, strlen(word));

    // A universal character name spells the same character with only basic
    // characters in the source file.
    const char *same = "é";
    printf("the two spellings are %s\n",
           strcmp(word, same) == 0 ? "identical" : "different");
    return 0;
}

// Output:
// '7' has the value 7
// 'A' = 65, 'a' = 97, '0' = 48, ' ' = 32
// '\0' = 0
// C23 additions: @ $ `
// "é" is 2 bytes long
// the two spellings are identical

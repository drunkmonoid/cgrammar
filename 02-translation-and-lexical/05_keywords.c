// -----------------------------------------------------------------------------
// 05_keywords.c - every keyword of C23
//
// Run:  scripts/run.sh 02-translation-and-lexical/05_keywords.c
// -----------------------------------------------------------------------------
//
// A keyword is a reserved word: it cannot be used as an identifier. C23 has
// 54. Fifteen of them are new in C23:
//
//     alignas  alignof  bool  constexpr  false  nullptr  static_assert
//     thread_local  true  typeof  typeof_unqual
//     _BitInt  _Decimal32  _Decimal64  _Decimal128
//
// Before C23, `bool`, `true`, `false`, `alignas`, `alignof`,
// `static_assert` and `thread_local` were macros from headers such as
// <stdbool.h>, standing for keywords spelled _Bool, _Alignas, _Alignof,
// _Static_assert and _Thread_local. Those older spellings still work as
// alternative spellings of the same keywords.
//
// The underscore-capital spelling was how C added keywords without breaking
// programs: such names were always reserved, so no valid program could be
// using them. C23 took the plain words at last, which means an old program
// with a variable called `bool` or `true` no longer compiles.
//
// Keywords are case-sensitive: `Int` and `WHILE` are ordinary identifiers.
// `main`, `printf`, `NULL` and `size_t` are not keywords either.

#include <stdio.h>

static const char *const keywords[] = {
    // Types and type specifiers
    "void", "char", "short", "int", "long", "float", "double", "signed",
    "unsigned", "bool", "_BitInt", "_Complex", "_Imaginary", "_Decimal32",
    "_Decimal64", "_Decimal128", "struct", "union", "enum", "typeof",
    "typeof_unqual", "_Atomic",
    // Storage class
    "auto", "constexpr", "extern", "register", "static", "thread_local",
    "typedef",
    // Qualifiers, function specifiers, alignment
    "const", "restrict", "volatile", "inline", "_Noreturn", "alignas",
    // Statements
    "if", "else", "switch", "case", "default", "while", "do", "for", "break",
    "continue", "goto", "return",
    // Operators and constants
    "sizeof", "alignof", "_Generic", "static_assert", "true", "false",
    "nullptr",
};

int main(void) {
    size_t count = sizeof keywords / sizeof keywords[0];
    printf("C23 has %zu keywords:\n", count);

    for (size_t i = 0; i < count; i++) {
        printf("%-14s%s", keywords[i], (i + 1) % 5 == 0 ? "\n" : "");
    }
    printf("\n");

    // Case matters: these are identifiers, not keywords.
    int Int = 1, WHILE = 2, True = 3;
    printf("Int + WHILE + True = %d\n", Int + WHILE + True);

    // The older spellings name the same keywords.
    _Bool old_style = 1;
    bool new_style = true;
    printf("_Bool and bool are the same type: %d\n", old_style == new_style);
    return 0;
}

// Output:
// C23 has 54 keywords:
// void          char          short         int           long
// float         double        signed        unsigned      bool
// _BitInt       _Complex      _Imaginary    _Decimal32    _Decimal64
// _Decimal128   struct        union         enum          typeof
// typeof_unqual _Atomic       auto          constexpr     extern
// register      static        thread_local  typedef       const
// restrict      volatile      inline        _Noreturn     alignas
// if            else          switch        case          default
// while         do            for           break         continue
// goto          return        sizeof        alignof       _Generic
// static_assert true          false         nullptr
// Int + WHILE + True = 6
// _Bool and bool are the same type: 1

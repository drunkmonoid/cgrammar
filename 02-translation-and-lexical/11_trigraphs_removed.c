// -----------------------------------------------------------------------------
// 11_trigraphs_removed.c - nine sequences that used to change meaning
//
// Run:  scripts/run.sh 02-translation-and-lexical/11_trigraphs_removed.c
// -----------------------------------------------------------------------------
// @flags -Wno-trigraphs
//
// From C89 to C17, translation phase 1 replaced nine three-character
// sequences, everywhere, including inside strings and comments:
//
//     ??=  #      ??(  [      ??<  {
//     ??/  \      ??)  ]      ??>  }
//     ??'  ^      ??!  |      ??-  ~
//
// They served the same keyboards as digraphs, but being replaced before
// tokenisation they caused real bugs:
//
//     puts("What??!");        printed  What|
//     // Is this right??/     the ??/ became a backslash, which spliced the
//     x = 1;                  next line into the comment
//
// C23 removed trigraphs. The sequences below are now what they look like.
//
// gcc and clang still warn "trigraph ignored" when they see one, which is
// why this file passes -Wno-trigraphs. With -std=c17 -pedantic the same
// source prints `What|` and `#`.

#include <stdio.h>
#include <string.h>

int main(void) {
    puts("What??!");
    puts("??=");
    printf("\"??=\" has %zu characters\n", strlen("??="));
    return 0;
}

// Output:
// What??!
// ??=
// "??=" has 3 characters

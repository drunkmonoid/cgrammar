// -----------------------------------------------------------------------------
// 03_tokens.c - the five kinds of token, and the longest-match rule
//
// Run:  scripts/run.sh 02-translation-and-lexical/03_tokens.c
// -----------------------------------------------------------------------------
//
// After preprocessing, a program is a sequence of tokens of five kinds:
//
//     keyword          int  return  while  nullptr
//     identifier       main  total  printf
//     constant         42  3.14  'x'  0x1F
//     string literal   "hello"
//     punctuator       + - * / = == ( ) { } [ ] ; , . -> ++ << <<= ...
//
// White space only separates tokens. Where two tokens cannot be confused it
// is optional: `a=b+c;` and `a = b + c ;` are the same six tokens.
//
// The tokeniser follows one rule, often called "maximal munch": at each
// point it takes the longest sequence of characters that can form a token,
// without looking at what would make sense later.
//
//     a+++b      is   a ++ + b       (not a + ++b)
//     a+++++b    is   a ++ ++ + b    a syntax error, although a++ + ++b
//                                    would be valid (see 04)
//     x---y      is   x -- - y
//     a<<=b      is   a <<= b
//
// The same rule is why `i = j/*p;` starts a comment instead of dividing by
// what p points to. Write `j / *p`.

#include <stdio.h>

int main(void) {
    int a = 5, b = 10;

    // a ++ + b: use a (5), add b, then a becomes 6.
    int r = a+++b;
    printf("a+++b = %d, afterwards a = %d\n", r, a);

    // Spaces change the tokens, and with them the meaning.
    a = 5;
    r = a + ++b;
    printf("a + ++b = %d, afterwards b = %d\n", r, b);

    int x = 9, y = 4;
    r = x---y;      // x -- - y
    printf("x---y = %d, afterwards x = %d\n", r, x);

    // The space is required here: `- -y` is two negations, `--y` would
    // decrement y.
    r = - -y;
    printf("- -y = %d, y is still %d\n", r, y);

    // Dividing by a dereferenced pointer needs a space, or parentheses.
    int *p = &y;
    r = x / *p;
    printf("x / *p = %d\n", r);
    return 0;
}

// Output:
// a+++b = 15, afterwards a = 6
// a + ++b = 16, afterwards b = 11
// x---y = 5, afterwards x = 8
// - -y = 4, y is still 4
// x / *p = 2

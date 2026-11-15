// -----------------------------------------------------------------------------
// 04_maximal_munch_error.c - a program that must NOT compile
//
// Run:  scripts/run.sh 02-translation-and-lexical/04_maximal_munch_error.c
// -----------------------------------------------------------------------------
// @build fail
//
// `a+++++b` could be read as `a++ + ++b`, which is a valid expression. The
// tokeniser does not try: it takes the longest token each time and produces
//
//     a  ++  ++  +  b
//
// The parser then sees `(a++)++`. The result of a++ is a value, not an
// object, so it cannot be incremented:
//
//     error: lvalue required as increment operand
//
// The standard uses this very expression as its example of the rule.

int main(void) {
    int a = 1, b = 2;
    return a+++++b;
}

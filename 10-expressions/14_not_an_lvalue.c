// -----------------------------------------------------------------------------
// 14_not_an_lvalue.c - a program that must NOT compile
//
// Run:  scripts/run.sh 10-expressions/14_not_an_lvalue.c
// -----------------------------------------------------------------------------
// @build fail
//
// The left operand of an assignment has to be an lvalue. 1 + 2 is a value.
// There is no object to store into.
//
//     error: lvalue required as left operand of assignment
//
// The same constraint rejects ++(n + 1) and &(1 + 2). The maximal-munch
// example in chapter 2 fails for this reason too: the tokens of a+++++b
// are a ++ ++ + b, and the second ++ is applied to a value.

int main(void) {
    return (1 + 2) = 3;
}

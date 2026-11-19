// -----------------------------------------------------------------------------
// 09_auto_needs_initializer.c - a program that must NOT compile
//
// Run:  scripts/run.sh 06-declarations/09_auto_needs_initializer.c
// -----------------------------------------------------------------------------
// @build fail
//
// auto with no type copies the type of the initializer. With no initializer
// there is no type to copy, and the declaration is ill-formed.
//
//     error: 'auto' requires an initialized data declaration
//
// An explicit type does not have this requirement. `int x;` is a valid
// declaration. Reading x before assigning to it is a separate problem,
// and it is undefined behaviour rather than a constraint violation.

int main(void) {
    auto x;
    return x;
}

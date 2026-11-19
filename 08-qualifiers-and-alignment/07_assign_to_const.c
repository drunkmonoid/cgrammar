// -----------------------------------------------------------------------------
// 07_assign_to_const.c - a program that must NOT compile
//
// Run:  scripts/run.sh 08-qualifiers-and-alignment/07_assign_to_const.c
// -----------------------------------------------------------------------------
// @build fail
//
// Assigning to a const object is a constraint violation.
//
//     error: assignment of read-only variable 'n'
//
// The same diagnostic covers ++n and n += 1. A pointer to const refuses
// the write at the pointer: *p = 1, where p has type const int *, fails
// for the same reason.

int main(void) {
    const int n = 1;
    n = 2;
    return n;
}

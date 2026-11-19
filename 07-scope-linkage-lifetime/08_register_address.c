// -----------------------------------------------------------------------------
// 08_register_address.c - a program that must NOT compile
//
// Run:  scripts/run.sh 07-scope-linkage-lifetime/08_register_address.c
// -----------------------------------------------------------------------------
// @build fail
//
// The address of an object declared register cannot be taken. That is a
// constraint, not a warning: the operand of & has to designate an object
// that is allowed to have an address.
//
//     error: address of register variable 'x' requested
//
// Drop register, or stop asking for the address. There is no third option.

int main(void) {
    register int x = 1;
    int *p = &x;
    return *p;
}

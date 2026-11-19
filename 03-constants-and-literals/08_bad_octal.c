// -----------------------------------------------------------------------------
// 08_bad_octal.c - a program that must NOT compile
//
// Run:  scripts/run.sh 03-constants-and-literals/08_bad_octal.c
// -----------------------------------------------------------------------------
// @build fail
//
// A constant that starts with 0 is octal. Octal digits stop at 7, so 08 is
// not a number with a useless leading zero; it is an ill-formed constant.
//
//     error: invalid digit "8" in octal constant
//
// The same rule rejects a digit separator in the wrong place (0x'FF, or a
// trailing 100'), and a u8 character constant whose character does not fit
// in one code unit.

int main(void) {
    return 08;
}

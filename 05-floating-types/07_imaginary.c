// -----------------------------------------------------------------------------
// 07_imaginary.c - the optional imaginary types
//
// Run:  scripts/run.sh 05-floating-types/07_imaginary.c
// -----------------------------------------------------------------------------
// @build skip imaginary types are optional and this toolchain does not provide them
//
// Annex G specifies float _Imaginary, double _Imaginary, and
// long double _Imaginary: a complex value whose real part is zero, stored
// as one real number. <complex.h> defines imaginary as a macro for
// _Imaginary when the implementation provides it.
//
// gcc 15 parses _Imaginary as an ordinary identifier. clang 21 reports
// that imaginary types are not supported. The complex types in the
// previous file are the portable way to write an imaginary number:
// 0.0 + 1.0 * I.

double _Imaginary unit(void) {
    return 1.0;
}

int main(void) {
    double _Imaginary x = unit();
    return x == 0.0;
}

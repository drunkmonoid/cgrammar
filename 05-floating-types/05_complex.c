// -----------------------------------------------------------------------------
// 05_complex.c - a real and an imaginary part, in one object
//
// Run:  scripts/run.sh 05-floating-types/05_complex.c
// -----------------------------------------------------------------------------
//
// float complex, double complex, and long double complex are the three
// complex types. Each holds two values of the corresponding real type.
// The keyword is _Complex; <complex.h> defines complex as a macro for it,
// and I as a constant of imaginary one.
//
//     3.0 + 4.0 * I
//
// creal and cimag read the parts back. cabs is the modulus. For 3 and 4
// that modulus is exactly 5, so the print is not a rounding accident.
// I * I is -1, which is the property the type exists to keep.
//
// sizeof(double complex) is twice sizeof(double). The same ratio holds for
// the other two widths. On this platform that is 8, 16, and 32.
//
// Annex G also specifies imaginary types, written _Imaginary. They are
// optional, and neither gcc 15 nor clang 21 provides them. The next file
// is the program they would accept. Complex types are not optional on a
// hosted implementation that defines __STDC_IEC_60559_COMPLEX__, and this
// one has them.

#include <complex.h>
#include <stdio.h>

int main(void) {
    double complex z = 3.0 + 4.0 * I;
    printf("%.1f %.1f %.1f\n", creal(z), cimag(z), cabs(z));
    printf("%.1f\n", creal(I * I));

    printf("%zu %zu %zu\n",
           sizeof(float complex), sizeof(double complex),
           sizeof(long double complex));
    return 0;
}

// Output:
// 3.0 4.0 5.0
// -1.0
// 8 16 32

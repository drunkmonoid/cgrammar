// -----------------------------------------------------------------------------
// 08_weaken_alignment.c - a program that must NOT compile
//
// Run:  scripts/run.sh 08-qualifiers-and-alignment/08_weaken_alignment.c
// -----------------------------------------------------------------------------
// @build fail
//
// alignas can raise the alignment of an object. It cannot lower it.
// An int is already aligned more strictly than 1, so this declaration
// asks for something the type forbids.
//
//     error: '_Alignas' specifiers cannot reduce alignment of 'x'

int main(void) {
    alignas(1) int x = 1;
    return x;
}

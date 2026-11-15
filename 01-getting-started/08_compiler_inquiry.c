// -----------------------------------------------------------------------------
// 08_compiler_inquiry.c - asking the compiler about itself
//
// Run:  scripts/run.sh 01-getting-started/08_compiler_inquiry.c
// -----------------------------------------------------------------------------
//
// The standard predefines a few macros that describe the translation:
//
//     __FILE__   name of the source file, as a string
//     __LINE__   current line number, as an integer
//     __DATE__   date of translation, "Mmm dd yyyy"
//     __TIME__   time of translation, "hh:mm:ss"
//     __func__   name of the enclosing function (an identifier, not a macro)
//
// Compilers add their own. __VERSION__ is common to gcc and clang.
// __GNUC__ is defined by gcc and also by clang, which imitates gcc; test
// __clang__ first to tell them apart.
//
// The output depends on the compiler and the day, so there is no Output
// block. __DATE__ and __TIME__ also make builds non-reproducible: the same
// source gives a different executable every second.

#include <stdio.h>

int main(void) {
#if defined(__clang__)
    printf("compiler: clang %d.%d.%d\n",
           __clang_major__, __clang_minor__, __clang_patchlevel__);
#elif defined(__GNUC__)
    printf("compiler: gcc %d.%d.%d\n",
           __GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__);
#else
    puts("compiler: unknown");
#endif

#ifdef __VERSION__
    printf("version string: %s\n", __VERSION__);
#endif

    printf("file: %s, line %d, function %s\n", __FILE__, __LINE__, __func__);
    printf("translated on %s at %s\n", __DATE__, __TIME__);
    return 0;
}

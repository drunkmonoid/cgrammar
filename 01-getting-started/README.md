# 01 — Getting Started

How to compile C, what a program looks like, where execution starts, and
what the program hands back when it ends.

## Examples

| File | Topic |
|---|---|
| [01_hello_world.c](01_hello_world.c) | Smallest complete program |
| [02_program_anatomy.c](02_program_anatomy.c) | Directives, declarations, definitions, and why order matters |
| [03_main_forms.c](03_main_forms.c) | `int main(void)` and `int main(int argc, char *argv[])` |
| [04_exit_status.c](04_exit_status.c) | `return` from `main`, `EXIT_SUCCESS`, `EXIT_FAILURE` |
| [05_first_printf.c](05_first_printf.c) | `printf` conversions, width, precision, `puts` |
| [06_first_input.c](06_first_input.c) | `fgets`, `scanf`, and checking that input worked |
| [07_hosted_and_freestanding.c](07_hosted_and_freestanding.c) | `__STDC_HOSTED__`, `__STDC_VERSION__` |
| [08_compiler_inquiry.c](08_compiler_inquiry.c) | `__FILE__`, `__LINE__`, `__func__`, compiler version macros |
| [09_undeclared_function_error.c](09_undeclared_function_error.c) | A program that must fail to compile |
| [10_translation_steps/](10_translation_steps/) | Preprocess, compile, assemble, link, one step at a time |
| [compilers.md](compilers.md) | Compilers, flags, file extensions |

## Compiling by hand

```sh
gcc -std=c23 -Wall -Wextra -pedantic -g hello.c -o hello
./hello
```

Or, inside this repository:

```sh
scripts/run.sh 01-getting-started/01_hello_world.c
scripts/check_all.sh 01-getting-started     # every example in the chapter
```

## Which C

| Standard | ISO | Highlights |
|---|---|---|
| C89 / C90 | 9899:1990 | The first standard: prototypes, `void`, `const`, the library |
| C99 | 9899:1999 | `//` comments, declarations anywhere, `long long`, `<stdint.h>`, designated initialisers, VLAs |
| C11 | 9899:2011 | `_Generic`, `_Alignas`, `_Atomic`, threads, anonymous structs, `gets` removed |
| C17 | 9899:2018 | Corrections only |
| **C23** | **9899:2024** | `bool`, `nullptr`, `constexpr`, `typeof`, `auto` inference, `_BitInt`, `[[attributes]]`, `#embed`, binary literals, K&R definitions removed |

This tutorial teaches the language as defined by **C23**. A file notes when
a feature arrived only where that matters for compiler support. Chapter 40
covers what older code looks like and what C23 removed.

## From source to executable

```
hello.c ──preprocess──▶ hello.i ──compile──▶ hello.s ──assemble──▶ hello.o ─┐
                                                                            ├─link──▶ hello
                                              other .o files, libc, libm ───┘
```

| Step | Flag to stop after it | Input → output |
|---|---|---|
| Preprocess | `-E` | Directives run; one C file with no `#` lines |
| Compile | `-S` | C → assembly |
| Assemble | `-c` | Assembly → object file with a symbol table |
| Link | — | Object files and libraries → executable |

Each `.c` file, together with everything it includes, is one **translation
unit**. The compiler sees one translation unit at a time and knows nothing
about the others; the linker joins them.

## Structure of a source file

```c
#include <stdio.h>          // directives

int helper(int n);          // declarations: say what exists

int main(void) {            // definitions: say what it is
    return helper(1);
}

int helper(int n) {
    return n - 1;
}
```

Only declarations may appear at the top level. A name must be declared
before the line that uses it.

## Key points

- A hosted program starts in `main`, which returns `int`.
- `int main(void)` and `int main(int argc, char *argv[])` are the two
  portable forms. `void main()` is not standard C.
- Falling off the end of `main` returns 0. No other function has that rule.
- Only `0`, `EXIT_SUCCESS` and `EXIT_FAILURE` have a portable meaning as
  exit status.
- Calling an undeclared function is an error. Include the header.
- `printf` conversions must match their arguments; `-Wall` checks them.
- Check the return value of every input function.
- Compile with warnings on from the first day. In C most mistakes compile.

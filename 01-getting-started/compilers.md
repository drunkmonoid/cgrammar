# Compilers, Flags and File Extensions

## Compilers

| Compiler | Command | C23 flag | Notes |
|---|---|---|---|
| GCC | `gcc` | `-std=c23` | C23 is the default from gcc 15. `-std=c2x` on gcc 13 and older |
| Clang | `clang` | `-std=c23` | `-std=c2x` before clang 18. Default is still C17 |
| MSVC | `cl` | `/std:clatest` | C11 and C17 are complete; C23 support is partial |
| TinyCC | `tcc` | — | Fast, small, mostly C99 with some C11 |

This tutorial is checked with gcc 15 and clang 21 on Linux with glibc 2.43.
The compiler is half of an implementation; the C library is the other half.
A C23 library function such as `memset_explicit` needs a recent glibc no
matter how new the compiler is.

## The flags used here

```sh
gcc -std=c23 -Wall -Wextra -pedantic -g file.c -o file -lm
```

| Flag | Effect |
|---|---|
| `-std=c23` | ISO C23. Without `-pedantic` GNU extensions are still accepted quietly |
| `-pedantic` | Diagnose everything the standard requires a diagnostic for, extensions included |
| `-Wall` | The warnings almost everyone wants: unused variables, bad format strings, missing returns |
| `-Wextra` | More: unused parameters, signed/unsigned comparison, missing initialisers |
| `-g` | Debug information for `gdb` and for sanitizer reports |
| `-o file` | Name of the output. The default is `a.out` |
| `-lm` | Link the math library. On Linux `<math.h>` functions live in `libm`, apart from `libc` |

`-std=gnu23` is the same language plus GNU extensions, and is what gcc
uses when no `-std` is given.

Libraries go **after** the files that use them: `gcc main.c -lm`, not
`gcc -lm main.c`. The linker reads left to right and takes from a library
only what is still undefined at that point.

## Flags worth knowing

| Flag | Effect |
|---|---|
| `-Werror` | Turn every warning into an error. `scripts/check_all.sh` adds it |
| `-O0` `-O1` `-O2` `-O3` | Optimisation level. `-O0` is the default |
| `-Og` | Optimise without hurting debugging |
| `-Os` | Optimise for size |
| `-fsanitize=address` | Detect out-of-bounds access, use after free, leaks at run time |
| `-fsanitize=undefined` | Detect signed overflow, bad shifts, null dereference and more at run time |
| `-fsanitize=thread` | Detect data races. Cannot be combined with the address sanitizer |
| `-fanalyzer` | gcc's static analyser |
| `-E` | Stop after preprocessing |
| `-S` | Stop after compiling to assembly |
| `-c` | Stop after assembling: produce an object file |
| `-I dir` | Add a directory to the `#include` search path |
| `-D NAME=value` | Define a macro, as `#define` would |
| `-L dir` `-l name` | Add a library search directory; link `libname` |
| `-ffreestanding` | Compile for a freestanding environment |

Chapter 41 returns to warnings, sanitizers and debuggers.

## File extensions

| Extension | Content |
|---|---|
| `.c` | C source. Preprocessed, then compiled |
| `.h` | Header: declarations shared between source files. Never compiled alone |
| `.i` | Preprocessed C. Compiled without preprocessing |
| `.s` | Assembly |
| `.S` | Assembly that is preprocessed first |
| `.o` | Object file |
| `.a` | Static library: an archive of object files |
| `.so` | Shared library (`.dylib` on macOS, `.dll` on Windows) |

The compiler driver chooses what to do from the extension. A file named
`.cpp`, `.cc` or `.C` is compiled as C++, which is a different language.

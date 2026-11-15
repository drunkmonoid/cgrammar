# Implementation Plan

Target language level: **C23** (ISO/IEC 9899:2024).
Phases 1–42 teach that language and its standard library, one topic per
file. Older standards appear only in phase 40, as the code you meet in
existing projects. What comes after phase 42 is sketched at the end and is
not scheduled yet.

Each phase is one directory, one commit, one push.
Status: `[x]` done · `[ ]` pending.

## Ground rules

- Every `.c` file at the top of a chapter directory is a complete program
  that compiles on its own. Files are numbered in reading order.
- Examples compile without warnings under

  ```
  gcc -std=c23 -Wall -Wextra -pedantic -g
  ```

  and again under `clang` with the same flags. `-std=c23 -pedantic` rejects
  GNU extensions, so anything that compiles here is standard C.
- A second pass adds `-fsanitize=address,undefined`. A program that is
  supposed to trip a sanitizer says so with a directive, and the check
  script expects it.
- Deterministic output is recorded in a trailing `// Output:` block, and a
  script compares those blocks with real runs.
- Directives in a comment near the top of a file tell the scripts how to
  treat it: `// @build fail` (must not compile), `// @build skip <reason>`,
  `// @flags <flags>`, `// @run no`, `// @exit <n>`, `// @args <args>`.
- A subdirectory with a `build.sh` is a multi-file example. It exits 77
  when a tool it needs is missing, so the full check stays green with only
  a compiler installed.
- Features the standard defines but the toolchain lacks are still written
  as complete examples and marked `@build skip`. Two are known already:
  decimal floating types under clang 21, and Annex K (`strcpy_s` and
  friends), which glibc does not provide.
- Each chapter has a `README.md` that states the rules and links every
  file. Later chapters cite earlier ones instead of repeating them.

A phase is done when its examples pass under both compilers and the
sanitizer pass, its `// Output:` blocks are verified, its README is
written, and `INDEX.md` is regenerated.

## Tracks

| Track | Phases | Aim |
|---|---|---|
| Foundations | 1–5 | Build a program, read its tokens, know the arithmetic types |
| Declarations and expressions | 6–12 | Declare any object and predict what any expression does |
| Functions, pointers, aggregates | 13–22 | The core of C: functions, memory, and the types built from other types |
| Preprocessor and program structure | 23–27 | Macros, generic selection, attributes, programs in several files |
| Standard library | 28–36 | Every header, grouped by what it is for |
| Concurrency | 37–38 | Threads and atomics as the standard defines them |
| Around the language | 39–42 | Undefined behaviour, older standards, tools, a support matrix |

## Foundations

| # | Status | Directory | Topic |
|---|---|---|---|
| 1 | [x] | `01-getting-started/` | Toolchain, the compile and link steps, program anatomy, both forms of `main`, exit status, hosted and freestanding, a first `printf` |
| 2 | [ ] | `02-translation-and-lexical/` | The eight translation phases, character sets, tokens, keywords, identifiers and reserved names, comments, line splicing, digraphs, the removal of trigraphs |
| 3 | [ ] | `03-constants-and-literals/` | Integer constants (decimal, octal, hex, binary, digit separators, suffixes), floating constants and hex floats, character constants, escape sequences, string literals and prefixes, `true`, `false`, `nullptr` |
| 4 | [ ] | `04-integer-types/` | `char` and its signedness, the standard integer types, `bool`, `<limits.h>` and the `_WIDTH` macros, `<stdint.h>`, `size_t`, `ptrdiff_t`, `_BitInt(N)`, two's complement, unsigned wraparound, signed overflow |
| 5 | [ ] | `05-floating-types/` | `float`, `double`, `long double`, `<float.h>`, IEC 60559, infinities and NaN, evaluation method, complex types, decimal floating types |

Phase 1 also delivers the scaffolding: `README.md`, `CONVENTIONS.md`,
`.gitignore`, `scripts/run.sh`, `scripts/check_all.sh`,
`scripts/check_outputs.sh`, `scripts/make_index.sh`, and a GitHub Actions
workflow that runs the full check under gcc and clang.

## Declarations and expressions

| # | Status | Directory | Topic |
|---|---|---|---|
| 6 | [ ] | `06-declarations/` | Specifiers and declarators, how to read a declaration, `typedef`, initialisation including `{}`, `auto` inference, `typeof` and `typeof_unqual`, `constexpr`, `static_assert` |
| 7 | [ ] | `07-scope-linkage-lifetime/` | The four scopes, name spaces, linkage, storage duration, the storage-class specifiers, tentative definitions, object lifetime |
| 8 | [ ] | `08-qualifiers-and-alignment/` | `const`, `volatile`, `restrict`, `_Atomic` as a qualifier, qualified pointers at every level, `alignas`, `alignof`, `max_align_t` |
| 9 | [ ] | `09-conversions/` | Integer promotions, conversion rank, usual arithmetic conversions, signed against unsigned comparison, real to integer and back, casts, lvalue conversion, array and function decay, conversion to `bool` |
| 10 | [ ] | `10-expressions/` | Lvalues, every operator, the precedence table, division and remainder, shifts, bitwise operators, short-circuit, the conditional and comma operators, `sizeof`, constant expressions |
| 11 | [ ] | `11-evaluation-order/` | Sequencing, full expressions, unsequenced side effects, argument evaluation order, what `&&`, `\|\|`, `?:` and `,` guarantee, and what nothing else does |
| 12 | [ ] | `12-statements/` | Compound and null statements, `if`, `switch` and fallthrough, `while`, `do`, `for`, `break`, `continue`, `goto` and labels (including the C23 placement rules), `return` |

## Functions, pointers, aggregates

| # | Status | Directory | Topic |
|---|---|---|---|
| 13 | [ ] | `13-functions/` | Definitions and prototypes, `()` as "no parameters", pass by value, array parameters, return values, recursion, `__func__`, the arguments of `main` |
| 14 | [ ] | `14-functions-advanced/` | `inline` and its linkage rules, `[[noreturn]]`, default argument promotions, `<stdarg.h>` with the one-argument `va_start`, `va_copy`, `vprintf` wrappers, function types |
| 15 | [ ] | `15-pointers/` | `&` and `*`, null pointers and `nullptr_t`, pointer arithmetic and its bounds, comparison, `void *`, pointers to pointers, dangling pointers |
| 16 | [ ] | `16-arrays/` | Declaration, designated initialisers, decay, arrays against pointers, multidimensional arrays, pointers to arrays, array parameters with `static`, variable length arrays and variably modified types |
| 17 | [ ] | `17-strings/` | Character arrays against literals, the terminator, `<string.h>` (`str*` and `mem*`), `<ctype.h>`, `strdup`, `memccpy`, `memset_explicit`, building strings with `snprintf`, the classic overflows |
| 18 | [ ] | `18-structures/` | Tags and members, designated and nested initialisation, assignment, padding and `offsetof`, compound literals, flexible array members, anonymous members, incomplete and opaque types, C23 tag compatibility |
| 19 | [ ] | `19-unions-bitfields-enums/` | Unions and tagged unions, reading a different member, bit-fields and what their layout leaves to the implementation, enumerations with a fixed underlying type |
| 20 | [ ] | `20-function-pointers/` | Declaring and calling through them, callbacks, `qsort` and `bsearch`, dispatch tables, declarators that mix arrays, pointers and functions |
| 21 | [ ] | `21-dynamic-memory/` | `malloc`, `calloc`, `realloc`, `free`, `aligned_alloc`, `free_sized`, ownership, leaks, double free, use after free, a growable array, a linked list, an arena |
| 22 | [ ] | `22-aliasing-and-effective-type/` | Effective type, the strict aliasing rule, access through character types, punning with `memcpy` and with unions, `restrict` in practice, provenance, `uintptr_t` round trips |

## Preprocessor and program structure

| # | Status | Directory | Topic |
|---|---|---|---|
| 23 | [ ] | `23-preprocessor/` | `#include` and `__has_include`, object-like and function-like macros, `#` and `##`, variadic macros and `__VA_OPT__`, conditional inclusion with `#elifdef`, `#error`, `#warning`, `#line`, `#pragma`, predefined macros |
| 24 | [ ] | `24-preprocessor-techniques/` | Include guards, macro pitfalls (double evaluation, missing parentheses, `do { } while (0)`), X-macros, argument counting, feature tests, `#embed` |
| 25 | [ ] | `25-generic-selection/` | `_Generic`, how the controlling expression is converted, type-generic macros, dispatch on several arguments, `<tgmath.h>` |
| 26 | [ ] | `26-attributes/` | `[[deprecated]]`, `[[fallthrough]]`, `[[maybe_unused]]`, `[[nodiscard]]`, `[[noreturn]]`, `[[unsequenced]]`, `[[reproducible]]`, `__has_c_attribute`, vendor attributes |
| 27 | [ ] | `27-multi-file-programs/` | Translation units, headers, declarations against definitions, internal linkage, `extern`, `inline` across units, opaque types behind a header, object files, static and shared libraries, `make` |

## Standard library

| # | Status | Directory | Topic |
|---|---|---|---|
| 28 | [ ] | `28-formatted-output/` | Every `printf` conversion, flags, width, precision, length modifiers, `%b`, `%wN`, `<inttypes.h>` macros, `snprintf` and truncation |
| 29 | [ ] | `29-formatted-input/` | Every `scanf` conversion, scansets, return values, the pitfalls, and reading lines with `fgets` plus `strtol` instead |
| 30 | [ ] | `30-file-io/` | Streams, `fopen` modes including `x`, character and line I/O, `fread` and `fwrite`, positioning, buffering, `tmpfile`, `remove`, `rename`, `feof` against `ferror` |
| 31 | [ ] | `31-errors-and-environment/` | `errno`, `strerror`, `perror`, `assert`, the five ways to terminate, `atexit`, `getenv`, `system`, `<signal.h>`, `<setjmp.h>` |
| 32 | [ ] | `32-stdlib-utilities/` | The `strtol` family and `strfrom*`, `rand`, `abs` and `div`, checked arithmetic in `<stdckdint.h>`, bit utilities in `<stdbit.h>` |
| 33 | [ ] | `33-math/` | `<math.h>` by family, classification macros, rounding functions, `math_errhandling`, `<fenv.h>` and the `STDC` pragmas, complex functions |
| 34 | [ ] | `34-time-and-locale/` | `time`, `clock`, `timespec_get`, broken-down time and the `_r` variants, `strftime`, `<locale.h>` and what a locale changes |
| 35 | [ ] | `35-wide-and-unicode/` | `wchar_t`, `<wchar.h>`, `<wctype.h>`, `char8_t`, `char16_t`, `char32_t`, `<uchar.h>`, multibyte conversion, walking UTF-8 by hand |
| 36 | [ ] | `36-library-catalog/` | Header by header: everything not shown elsewhere, the freestanding subset, the obsolescent headers, Annex K |

## Concurrency

| # | Status | Directory | Topic |
|---|---|---|---|
| 37 | [ ] | `37-threads/` | `<threads.h>`: creating and joining threads, mutexes, condition variables, `call_once`, `thread_local` and thread-specific storage |
| 38 | [ ] | `38-atomics/` | `<stdatomic.h>`: `_Atomic` objects, `atomic_flag`, memory orders, compare-exchange, lock-freedom, a data race shown under the thread sanitizer |

## Around the language

| # | Status | Directory | Topic |
|---|---|---|---|
| 39 | [ ] | `39-undefined-behavior/` | Undefined, unspecified and implementation-defined behaviour, a catalogue with one program each, what the optimiser does with it, which sanitizer catches which, `unreachable()` |
| 40 | [ ] | `40-older-standards/` | C89, C99, C11 and C17 as you meet them in existing code, and what C23 removed: K&R definitions, implicit `int`, implicit function declarations, `gets`, trigraphs |
| 41 | [ ] | `41-tooling/` | Warning flags, sanitizers, `gdb`, the static analysers, formatting, `make`, CMake, `pkg-config`, building with a second compiler |
| 42 | [ ] | `42-support-and-index/` | A C23 feature matrix for gcc and clang, a glossary, the complete index, and a full verification run under both compilers and the sanitizers |

## After phase 42

Not scheduled. Candidates, in rough order: data structures (stacks, hash
maps, heaps, graphs), text (a lexer, a recursive-descent parser, an
evaluator), POSIX and systems programming, numerical methods, calling C
from other languages, and exercises with solutions for each track.

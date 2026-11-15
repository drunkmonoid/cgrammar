# Conventions

## Layout

```
NN-topic/
  README.md             explanation of the chapter, links to every example
  MM_subtopic.c         one standalone program per subtopic
  MM_subtopic/          multi-file example (headers, libraries, make, ...)
    build.sh            builds and runs it (see below)
```

Every `.c` file at the top of a chapter directory is a complete program that
can be compiled on its own. Files are numbered in reading order.

## Language level

All examples target **C23** (ISO/IEC 9899:2024) and are compiled with

```
gcc -std=c23 -Wall -Wextra -pedantic -g file.c -lm
```

and with `clang` using the same flags. `-std=c23 -pedantic` turns GNU
extensions into diagnostics, so anything that compiles here is standard C.
`scripts/check_all.sh` adds `-Werror`: an example may not warn unless
warning is its subject.

Features that the standard defines but the toolchain does not provide are
still documented; those files are marked `@build skip` with the reason.

## Build directives

A comment line of the form `// @key value` near the top of a file tells the
scripts how to treat it:

| Directive | Meaning |
|---|---|
| `// @build fail` | Must **fail** to compile (demonstrates a compile-time error) |
| `// @build skip <reason>` | Not compiled (the toolchain lacks the feature) |
| `// @only <gcc\|clang> <reason>` | Built with that compiler only, skipped under the other |
| `// @flags <flags>` | Extra compiler flags, placed after `CFLAGS` (a later `-std=` wins) |
| `// @flags -Wno-error` | The example warns on purpose |
| `// @libs <libs>` | Extra libraries, placed after `-lm` |
| `// @run no` | Compile only, do not run |
| `// @exit <n>` | Program is expected to terminate with exit status `n` |
| `// @args <args>` | Command-line arguments passed when run by the scripts |
| `// @stdin <text>` | Standard input for the run; `\n` is a newline |
| `// @san fail` | Under `SAN=1` a sanitizer must stop the program |
| `// @san skip <reason>` | Not built under `SAN=1` |

## Sanitizers

`SAN=1 scripts/check_all.sh` rebuilds everything with
`-fsanitize=address,undefined -fno-sanitize-recover=all`. Every example
must run clean under them, with two exceptions. A program whose subject is
a bug carries `@san fail`: the sanitizer report is the lesson. A program
the sanitizers cannot run carries `@san skip` and the reason.

## Multi-file examples

A subdirectory containing `build.sh` is a multi-file example. The script
runs with the example's directory as the working directory and these
environment variables set. It must exit non-zero on failure. Exit status 77
means "skipped": a required tool is missing, and the last line printed is
shown as the reason.

| Variable | Meaning |
|---|---|
| `CC` | C compiler |
| `CFLAGS` | Standard flags (above) |
| `LDLIBS` | Libraries to link (`-lm`) |
| `OUT` | Empty directory to put objects, libraries and executables in |

The first comment line of `build.sh` is the example's description in
`INDEX.md`.

## Style

- Four-space indentation, opening brace on the same line, `//` comments.
- `int main(void)` unless the program reads its arguments.
- C23 spellings: `bool`, `true`, `false`, `nullptr`, `static_assert`,
  `alignas`, `alignof`, `thread_local`. The older `_Bool`-style spellings
  appear only in the chapter on older standards.
- Each file starts with a header line `// NN_name.c - description`, which
  `scripts/make_index.sh` collects into `INDEX.md`.
- Comments explain *why* and *what the rule is*. Output the program prints
  is shown in a trailing `// Output:` block when it is deterministic.
  `scripts/check_outputs.sh` verifies those blocks against real runs.
- Where a result depends on the implementation (the size of `long`, the
  signedness of `char`), the comment says so and the recorded output is the
  one for x86-64 Linux.

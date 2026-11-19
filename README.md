# C Grammar

A comprehensive, example-driven tutorial of **modern C (C23)**: every part
of the language and its standard library, one topic per file.

- Every example is a small, complete, heavily commented program.
- Every example compiles without warnings under `gcc -std=c23 -pedantic`
  and under `clang` with the same flags, so it is standard C, not a
  compiler dialect.
- Every example runs clean under the address and undefined-behaviour
  sanitizers, unless a bug is its subject.
- Each chapter has a `README.md` summarising the rules and linking its files.

Start here:

- [INDEX.md](INDEX.md) — every example in the repository, one line each
- [PLAN.md](PLAN.md) — the 42-phase roadmap
- [CONVENTIONS.md](CONVENTIONS.md) — file layout and build directives

## Quick start

```sh
scripts/run.sh 01-getting-started/01_hello_world.c    # build + run one example
scripts/check_all.sh                                  # build + run everything
scripts/check_all.sh 01-getting-started               # one chapter
scripts/run.sh 01-getting-started/10_translation_steps/   # a multi-file example
CC=clang scripts/check_all.sh                         # another compiler
SAN=1 scripts/check_all.sh                            # under the sanitizers
scripts/check_outputs.sh                              # verify every "// Output:" block
scripts/make_index.sh > INDEX.md                      # regenerate the index
```

Requires `gcc` 15 or `clang` 21 (or newer), a C library with the C23
additions (glibc 2.43), and `bash`.

## Chapters

| # | Chapter | Status |
|---|---|---|
| 01 | [Getting started](01-getting-started/) | ✅ |
| 02 | [Translation phases and lexical elements](02-translation-and-lexical/) | ✅ |
| 03 | [Constants and literals](03-constants-and-literals/) | ✅ |

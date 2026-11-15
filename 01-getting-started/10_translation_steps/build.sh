# The four steps from source to executable, run one at a time.
#
# Usage: scripts/run.sh 01-getting-started/10_translation_steps/
#
# `gcc main.c greet.c -o hello` does all of this in one command. Here each
# step writes a file you can open.
set -eu

# 1. Preprocess: run the directives. #include is replaced by the header's
#    text, macros are expanded, comments become spaces. The result is still
#    C, in one file with no directives left.
$CC $CFLAGS -E greet.c -o "$OUT/greet.i"
grep -q '"Hello"' "$OUT/greet.i"            # GREETING was expanded
! grep -q 'GREETING' "$OUT/greet.i"         # and the macro name is gone

# 2. Compile: translate preprocessed C to assembly for the target machine.
$CC $CFLAGS -S "$OUT/greet.i" -o "$OUT/greet.s"

# 3. Assemble: turn assembly into an object file. It holds machine code and
#    a symbol table: the names it defines and the names it still needs.
$CC -c "$OUT/greet.s" -o "$OUT/greet.o"

# Steps 1 to 3 in one command, which is what build systems run per file.
$CC $CFLAGS -c main.c -o "$OUT/main.o"

# main.o calls greet but does not define it: the symbol is undefined (U).
# greet.o defines it in the text section (T).
if command -v nm >/dev/null; then
    nm "$OUT/main.o" | grep ' U greet'
    nm "$OUT/greet.o" | grep ' T greet'
fi

# 4. Link: join the object files and the C library, and resolve each
#    undefined symbol to its definition.
$CC $CFLAGS "$OUT/main.o" "$OUT/greet.o" -o "$OUT/hello" $LDLIBS

"$OUT/hello"

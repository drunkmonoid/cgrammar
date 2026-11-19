# An external definition in one file, used from another.

# value.c defines shared and value. main.c declares them and calls them.
# hidden is static, so it has internal linkage: this file may use it, and
# the other file cannot name it. A second definition of shared would fail
# at link time.
set -eu

"$CC" $CFLAGS -c value.c -o "$OUT/value.o"
"$CC" $CFLAGS -c main.c -o "$OUT/main.o"
"$CC" $CFLAGS "$OUT/value.o" "$OUT/main.o" -o "$OUT/a.out" $LDLIBS

got=$("$OUT/a.out")
[ "$got" = "42" ]

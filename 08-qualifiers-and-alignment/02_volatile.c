// -----------------------------------------------------------------------------
// 02_volatile.c - an access the compiler must actually perform
//
// Run:  scripts/run.sh 08-qualifiers-and-alignment/02_volatile.c
// -----------------------------------------------------------------------------
//
// volatile is a qualifier on an object whose value can change, or whose
// being read or written is itself an effect, outside the abstract machine's
// normal data flow. Memory-mapped registers are the usual case. A signal
// handler writing a sig_atomic_t that the program reads is another.
//
// The compiler may not delete a volatile access, combine two of them, or
// reorder them relative to other observable behaviour, as far as the
// machine can honour that. Two stores remain two stores. A read between
// them sees the value the first store wrote.
//
// volatile is not atomic (file 04), and it is not a memory order for
// threads (chapter 38). It says each access happens. It does not say the
// access is indivisible, and it does not say anything about another thread.
//
// The qualifier is part of the type. A volatile int * is not an int *.
// Adding volatile to a pointer conversion is allowed; removing it is not,
// for the same reason removing const is not.

#include <stdio.h>

int main(void) {
    volatile int x = 1;
    x = 2;
    int first = x;
    x = 3;
    int second = x;

    printf("%d %d\n", first, second);
    return 0;
}

// Output:
// 2 3

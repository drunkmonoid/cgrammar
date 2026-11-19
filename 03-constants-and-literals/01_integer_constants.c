// -----------------------------------------------------------------------------
// 01_integer_constants.c - decimal, octal, hex, binary, and digit separators
//
// Run:  scripts/run.sh 03-constants-and-literals/01_integer_constants.c
// -----------------------------------------------------------------------------
//
// An integer constant is a token. Its base is written into the spelling:
//
//     42        decimal
//     052       octal, because it starts with 0
//     0x2a      hexadecimal
//     0b101010  binary          (C23)
//
// The leading zero is easy to miss, and it changes the value: 012 is ten,
// not twelve. Hex digits run 0–9 then a–f, in either case. Binary digits
// are only 0 and 1. 0b and 0B are the same prefix, as are 0x and 0X.
//
// A ' between digits is a digit separator (C23). It does not change the
// value; it only groups digits for the reader. It may not start or end
// the number, sit next to another separator, or come immediately after
// the base prefix, so 0x'FF is not a constant.
//
// The type of the constant is a separate question, answered in the next
// file. Everything printed here fits in an int.

#include <stdio.h>

int main(void) {
    printf("%d %d %d %d\n", 42, 052, 0x2a, 0b101010);
    printf("012 is %d, not 12\n", 012);

    // Separators are ignored by the value. 1'000'000 is one million.
    printf("%d\n", 1'000'000);
    printf("%d %d\n", 0xFF'FF, 0b1010'1100);

    // Case does not matter in a prefix or a hex digit.
    printf("%d %d\n", 0X2A, 0B1111);
    return 0;
}

// Output:
// 42 42 42 42
// 012 is 10, not 12
// 1000000
// 65535 172
// 42 15

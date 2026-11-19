# 09 — Conversions

What happens to a value when an operator needs a different type: the
integer promotions, conversion rank, the usual arithmetic conversions,
casts, the decays, and the conversion to `bool`.

## Examples

| File | Topic |
|---|---|
| [01_integer_promotions.c](01_integer_promotions.c) | Narrow integers become `int` |
| [02_conversion_rank.c](02_conversion_rank.c) | Which integer type wins |
| [03_usual_arithmetic_conversions.c](03_usual_arithmetic_conversions.c) | One type for both operands |
| [04_signed_unsigned.c](04_signed_unsigned.c) | The conversion, written as a cast |
| [05_signed_unsigned_compare.c](05_signed_unsigned_compare.c) | The comparison without the cast |
| [06_real_and_integer.c](06_real_and_integer.c) | Truncation toward zero, and a float that cannot hold an int |
| [07_casts.c](07_casts.c) | A conversion written in the source |
| [08_decay.c](08_decay.c) | Lvalue conversion, arrays, and functions |
| [09_to_bool.c](09_to_bool.c) | Zero and only zero is false |

## Integer promotions

A type promotes to `int` when `int` can represent every value of it, and
to `unsigned int` otherwise. With a 32-bit `int`, `unsigned short` promotes
to `int`. Arithmetic on two `short` values is `int` arithmetic.

`_BitInt` is not promoted.

## Usual arithmetic conversions

Floating wins over integer, and the wider floating type wins. Otherwise
the promotions happen, then the rank rules of file 02 decide. A negative
signed value converted to unsigned becomes a large positive value.

## Key points

- The type of `a + b` does not depend on what you store it in.
- `(int)2.9` is 2. The conversion truncates toward zero.
- An array decays to a pointer except under `sizeof`, `typeof`, `alignof`, and unary `&`.
- `if (p)` converts `p` to `bool`. A null pointer is the false case.

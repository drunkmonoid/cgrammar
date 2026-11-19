# 05 — Floating Types

`float`, `double`, `long double`, the macros in `<float.h>`, infinities
and NaNs, how much extra precision an expression may use, complex types,
and the decimal types.

## Examples

| File | Topic |
|---|---|
| [01_real_types.c](01_real_types.c) | The three real types, and why 0.1 is not exact |
| [02_float_h.c](02_float_h.c) | `<float.h>` and Annex F |
| [03_infinities_and_nan.c](03_infinities_and_nan.c) | `INFINITY`, `NAN`, signed zero |
| [04_evaluation.c](04_evaluation.c) | `FLT_EVAL_METHOD` |
| [05_complex.c](05_complex.c) | `double complex` and `I` |
| [06_decimal.c](06_decimal.c) | `_Decimal32`, `_Decimal64`, `_Decimal128` |
| [07_imaginary.c](07_imaginary.c) | `_Imaginary`, not provided here |

## Widths on x86-64 Linux

| Type | Bytes | Significand bits |
|---|---|---|
| `float` | 4 | 24 |
| `double` | 8 | 53 |
| `long double` | 16 | 64 |

`long double` here is 80-bit extended precision, not binary128.

## Key points

- A decimal fraction is usually not the binary value you get.
- A NaN compares unequal to itself. `isinf` is true for both signs of infinity.
- `FLT_EVAL_METHOD` is 0 here: operations are rounded to the type of the operands.
- Complex types are real pairs. Imaginary types are optional, and absent.
- Decimal floating types are part of C23. gcc 15 compiles them; clang 21 does not.

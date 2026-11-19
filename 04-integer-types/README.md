# 04 — Integer Types

`char` and its signedness, the standard integers, `bool`, the limits and
width macros, the types in `<stdint.h>`, bit-precise integers, and the
two arithmetic rules: unsigned wrap is defined, signed overflow is not.

## Examples

| File | Topic |
|---|---|
| [01_char_signedness.c](01_char_signedness.c) | `char`, `signed char`, `unsigned char` |
| [02_standard_integers.c](02_standard_integers.c) | `short`, `int`, `long`, `long long` |
| [03_bool.c](03_bool.c) | `bool` stores 0 or 1 |
| [04_limits.c](04_limits.c) | `<limits.h>` and the `_WIDTH` macros |
| [05_stdint.c](05_stdint.c) | Exact widths, `size_t`, `ptrdiff_t` |
| [06_bitint.c](06_bitint.c) | `_BitInt(N)` |
| [07_twos_complement.c](07_twos_complement.c) | The representation C23 requires |
| [08_unsigned_wrap.c](08_unsigned_wrap.c) | Modular arithmetic |
| [09_signed_overflow.c](09_signed_overflow.c) | Undefined, and caught by the sanitizer |

## Minimum widths

| Type | At least |
|---|---|
| `char` | 8 |
| `short` | 16 |
| `int` | 16 |
| `long` | 32 |
| `long long` | 64 |

On x86-64 Linux the sizes are 1, 2, 4, 8, and 8 bytes. `long` is not a
64-bit type on every platform. `int32_t` is.

## Key points

- `char`, `signed char`, and `unsigned char` are three types. Plain `char`
  is signed on this platform.
- `bool` converts every nonzero value to 1.
- `INT_WIDTH` counts value bits. `sizeof` counts bytes, padding included.
- A `_BitInt` is not promoted to `int` when it stands alone.
- Unsigned overflow wraps. Signed overflow is undefined. Do not negate
  `INT_MIN`.

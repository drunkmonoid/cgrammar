# 03 — Constants and Literals

The tokens that are values: integer and floating constants, character
constants, string literals, and the three keywords `true`, `false`, and
`nullptr`.

## Examples

| File | Topic |
|---|---|
| [01_integer_constants.c](01_integer_constants.c) | Decimal, octal, hex, binary, digit separators |
| [02_integer_suffixes.c](02_integer_suffixes.c) | Which type a constant has; `u`, `l`, `ll`, `wb` |
| [03_floating_constants.c](03_floating_constants.c) | `f` and `L`, decimal and hexadecimal floats |
| [04_character_constants.c](04_character_constants.c) | `'A'` has type `int`; the prefixed forms |
| [05_escape_sequences.c](05_escape_sequences.c) | Named escapes, octal, hex, universal names |
| [06_string_literals.c](06_string_literals.c) | Prefixes, phase-6 concatenation, embedded nulls |
| [07_boolean_and_nullptr.c](07_boolean_and_nullptr.c) | `true`, `false`, `nullptr` |
| [08_bad_octal.c](08_bad_octal.c) | `08` must not compile |

## Integer constants

| Spelling | Base | Type list, first that fits |
|---|---|---|
| `42` | 10 | `int`, `long`, `long long` |
| `052` | 8 | `int`, `unsigned int`, `long`, `unsigned long`, `long long`, `unsigned long long` |
| `0x2a` | 16 | same as octal |
| `0b101010` | 2 | same as octal |

A suffix (`u`, `l`, `ll`, and combinations) starts the search at a later
type. `wb` / `uwb` select a bit-precise type. `'` between digits is ignored.

`2147483648` and `0x80000000` are the same value and, on a 32-bit `int`,
not the same type. Decimal does not try `unsigned int`; hexadecimal does.

## Floating constants

No suffix means `double`, `f` means `float`, `l` means `long double`.
`0x1.8p1` is a hexadecimal float: a hex significand times a power of two.

## Character constants and strings

| Token | Type |
|---|---|
| `'A'` | `int` |
| `u8'A'` | `unsigned char` |
| `u'A'` | `char16_t` |
| `U'A'` | `char32_t` |
| `L'A'` | `wchar_t` |
| `"ab"` | array of 3 `char` |
| `u8"ab"` | array of 3 `char8_t` |
| `u"ab"` | array of 3 `char16_t` |
| `U"ab"` | array of 3 `char32_t` |
| `L"ab"` | array of 3 `wchar_t` |

An ordinary string literal may be concatenated with one prefixed kind.
`u`, `U`, and `L` do not mix with each other or with `u8`.

## Key points

- A leading zero makes an integer constant octal.
- `'A'` has type `int`. `"A"` is an array of two `char`, including the null.
- The source spelling of a string is not modified when it is concatenated:
  escapes are processed first.
- `true` and `false` have type `bool`. `nullptr` has type `nullptr_t`.
- Modifying a string literal is undefined behaviour.

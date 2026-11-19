# 06 — Declarations

How a declaration is put together, how to read one, names for types,
initializers, and the four C23 tools that ask the compiler to work a
type or a value out for you: `auto`, `typeof`, `constexpr`, and
`static_assert`.

## Examples

| File | Topic |
|---|---|
| [01_specifiers_and_declarators.c](01_specifiers_and_declarators.c) | Specifiers describe the base; the declarator wraps it |
| [02_reading_declarations.c](02_reading_declarations.c) | `*a[4]` against `(*a)[4]` |
| [03_typedef.c](03_typedef.c) | A name for a type, and where `const` lands |
| [04_initialization.c](04_initialization.c) | Lists, designators, and `{}` |
| [05_auto.c](05_auto.c) | The type of the initializer |
| [06_typeof.c](06_typeof.c) | `typeof` and `typeof_unqual` |
| [07_constexpr.c](07_constexpr.c) | An object usable as a constant expression |
| [08_static_assert.c](08_static_assert.c) | A translation-time check |
| [09_auto_needs_initializer.c](09_auto_needs_initializer.c) | `auto` with nothing to copy must not compile |

## Reading a declarator

Start at the name. Take the postfix `[]` and `()` first, then the prefix
`*`, and respect parentheses.

| Declaration | Reading |
|---|---|
| `int *p` | pointer to `int` |
| `int a[4]` | array of 4 `int` |
| `int *a[4]` | array of 4 pointers to `int` |
| `int (*a)[4]` | pointer to an array of 4 `int` |
| `int *f(int)` | function returning a pointer to `int` |

## Key points

- The `*` binds to the declarator. `int *p, n;` declares one pointer and one `int`.
- `const` on a typedef name qualifies that name. `const ptr` is not `const int *`.
- `{}` zero-initializes any object, scalar or aggregate.
- `auto` decays arrays and drops top-level qualifiers. `typeof` does neither.
- `constexpr` applies to objects, not to functions, and it implies `const`.
- `static_assert` with no message is C23. The check is an integer constant expression.

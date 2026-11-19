# 08 — Qualifiers and Alignment

`const`, `volatile`, `restrict`, `_Atomic`, and the alignment of an object.

## Examples

| File | Topic |
|---|---|
| [01_const.c](01_const.c) | Which thing `const` freezes |
| [02_volatile.c](02_volatile.c) | Accesses the compiler must keep |
| [03_restrict.c](03_restrict.c) | A promise of no aliasing |
| [04_atomic.c](04_atomic.c) | `_Atomic` as a qualifier |
| [05_qualified_pointers.c](05_qualified_pointers.c) | A qualifier at every `*` |
| [06_alignment.c](06_alignment.c) | `alignas`, `alignof`, `max_align_t` |
| [07_assign_to_const.c](07_assign_to_const.c) | Writing a `const` object must not compile |
| [08_weaken_alignment.c](08_weaken_alignment.c) | `alignas` cannot lower an alignment |

## Where the qualifier sits

| Declaration | What is restricted |
|---|---|
| `const int n` | `n` cannot be modified |
| `const int *p` | `*p` cannot be modified; `p` can be reseated |
| `int *const p` | `p` cannot be reseated; `*p` can be modified |
| `const int *const p` | neither can be modified |

`int *` converts to `const int *`. `int **` does not convert to `const int **`.

## Key points

- `const` is not a constant expression. `constexpr` is.
- `volatile` keeps the access. It does not make the access atomic.
- Breaking a `restrict` promise is undefined behaviour.
- `_Atomic int` and `_Atomic(int)` are the same type. Ordering is chapter 38.
- `alignof` takes a type. `alignas` takes a constant or a type, and it may only get stricter.

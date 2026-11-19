# 10 — Expressions

The operators, the precedence that groups them, and where a constant
expression is required.

## Examples

| File | Topic |
|---|---|
| [01_lvalues.c](01_lvalues.c) | What may be assigned to |
| [02_arithmetic.c](02_arithmetic.c) | `+` `-` `*` and the unary forms |
| [03_division_remainder.c](03_division_remainder.c) | Toward zero, and `(a/b)*b + a%b == a` |
| [04_shifts.c](04_shifts.c) | `<<` `>>`, and the cases that are undefined |
| [05_bitwise.c](05_bitwise.c) | `&` `|` `^` `~` |
| [06_relational_logical.c](06_relational_logical.c) | Comparisons, `&&` `||` `!` |
| [07_conditional_comma.c](07_conditional_comma.c) | `?:` and the comma operator |
| [08_assignment.c](08_assignment.c) | `=` , the compound forms, `++` `--` |
| [09_postfix.c](09_postfix.c) | `[]` `.` `->` and the call |
| [10_sizeof.c](10_sizeof.c) | When the operand is evaluated |
| [11_precedence.c](11_precedence.c) | The grouping, written with parentheses |
| [12_precedence_traps.c](12_precedence_traps.c) | The same grouping, without them |
| [13_constant_expressions.c](13_constant_expressions.c) | What may be a case label or an array length |
| [14_not_an_lvalue.c](14_not_an_lvalue.c) | Assigning to a value must not compile |

## Precedence

Postfix operators bind tightest, then prefix operators and casts, then the
arithmetic and bitwise operators in the order `* / %`, `+ -`, `<< >>`,
the comparisons, `&`, `^`, `|`, `&&`, `||`, `?:`, assignment, and finally
the comma. Assignment and `?:` associate right to left. The arithmetic
operators associate left to right.

`<<` binds looser than `+`. `==` binds tighter than `&`.

## Key points

- Integer division truncates toward zero. The remainder takes the sign of the dividend.
- `&&` and `||` yield 0 or 1, and they do not evaluate the right operand when the left already decides.
- `&` does not skip an operand. `&&` does.
- `sizeof` does not evaluate its operand, except when the operand is a variable-length array.
- A right shift of a negative value is implementation-defined. Shift unsigned values.
- An integer constant expression may size an array and label a `case`. A floating constant may not.

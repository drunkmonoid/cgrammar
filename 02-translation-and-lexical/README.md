# 02 — Translation Phases and Lexical Elements

How the text of a source file becomes tokens: the order in which the
compiler processes it, which characters it may contain, and what a name, a
keyword and a comment are.

## Examples

| File | Topic |
|---|---|
| [01_translation_phases.c](01_translation_phases.c) | The eight phases, and behaviour that follows from their order |
| [02_character_sets.c](02_character_sets.c) | Basic and extended characters, source and execution sets, UTF-8 |
| [03_tokens.c](03_tokens.c) | The five kinds of token; the longest-match rule |
| [04_maximal_munch_error.c](04_maximal_munch_error.c) | `a+++++b` must fail to compile |
| [05_keywords.c](05_keywords.c) | All 54 keywords; the fifteen C23 added |
| [06_identifiers.c](06_identifiers.c) | Spelling rules, case, significant length, Unicode names |
| [07_reserved_identifiers.c](07_reserved_identifiers.c) | Underscore rules, library names, potentially reserved patterns |
| [08_comments.c](08_comments.c) | `/* */`, `//`, no nesting, `#if 0` |
| [09_line_splicing.c](09_line_splicing.c) | Backslash-newline in macros, strings and tokens |
| [10_digraphs.c](10_digraphs.c) | `<:` `:>` `<%` `%>` `%:` `%:%:` and `<iso646.h>` |
| [11_trigraphs_removed.c](11_trigraphs_removed.c) | `??=` and friends, gone in C23 |
| [12_whitespace_and_layout.c](12_whitespace_and_layout.c) | Free-form layout and the three places white space counts |

## The translation phases

| Phase | What happens |
|---|---|
| 1 | Bytes of the file are mapped to the source character set |
| 2 | Backslash-newline pairs are deleted (line splicing) |
| 3 | Text is split into preprocessing tokens; each comment becomes a space |
| 4 | Directives are executed and macros expanded; `#include` files go through 1–4 |
| 5 | Characters and escapes in literals are converted to the execution character set |
| 6 | Adjacent string literals are concatenated |
| 7 | Tokens are parsed, checked and translated |
| 8 | Translation units and libraries are linked |

## Tokens

| Kind | Examples |
|---|---|
| Keyword | `int` `return` `sizeof` `nullptr` |
| Identifier | `main` `total` `printf` |
| Constant | `42` `0x1F` `3.14` `'x'` `true` |
| String literal | `"hello"` `u8"hello"` |
| Punctuator | see below |

The tokeniser always takes the longest possible token: `a+++b` is
`a ++ + b`.

## Punctuators

```
[ ] ( ) { } . ->
++ -- & * + - ~ !
/ % << >> < > <= >= == != ^ | && ||
? : :: ; ...
= *= /= %= += -= <<= >>= &= ^= |=
, # ##
<: :> <% %> %: %:%:
```

`::` is new in C23 and appears only inside attributes (`[[gnu::packed]]`).
`#` and `##` are punctuators for the preprocessor only.

## Keywords

```
alignas       constexpr   extern     int        signed          typedef         while
alignof       continue    false      long       sizeof          typeof          _Atomic
auto          default     float      nullptr    static          typeof_unqual   _BitInt
bool          do          for        register   static_assert   union           _Complex
break         double      goto       restrict   struct          unsigned        _Decimal128
case          else        if         return     switch          void            _Decimal32
char          enum        inline     short      thread_local    volatile        _Decimal64
const                                           true                            _Generic
                                                                                _Imaginary
                                                                                _Noreturn
```

Alternative spellings of five keywords: `_Alignas`, `_Alignof`, `_Bool`,
`_Static_assert`, `_Thread_local`.

## Reserved identifiers

| Pattern | Reserved |
|---|---|
| `__name`, `_Name` | Always |
| `_name` | At file scope |
| Library names (`printf`, `size_t`, ...) | As external names always; otherwise when the header is included |
| `str…`, `mem…`, `is…`, `to…` + lowercase, `E` + digit or capital | Potentially: a future standard may define them |

## Key points

- Comments are removed in phase 3, before macros are expanded.
- Block comments do not nest. Disable code with `#if 0`.
- A backslash at the end of a line joins it to the next, even inside a
  `//` comment.
- Macro names inside string literals are not expanded.
- Adjacent string literals are joined after escapes are processed.
- Identifiers are case-sensitive and may contain Unicode letters.
- Do not start your own names with an underscore.
- Trigraphs no longer exist in C23; digraphs still do.

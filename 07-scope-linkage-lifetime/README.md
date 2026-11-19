# 07 — Scope, Linkage, and Lifetime

Where a name can be seen, when two declarations are the same entity, and
how long the storage lasts.

## Examples

| File | Topic |
|---|---|
| [01_scopes.c](01_scopes.c) | File, block, prototype, and function scope |
| [02_name_spaces.c](02_name_spaces.c) | Labels, tags, members, ordinary identifiers |
| [03_linkage.c](03_linkage.c) | External, internal, and none |
| [04_storage_duration.c](04_storage_duration.c) | Automatic, static, and thread |
| [05_storage_class.c](05_storage_class.c) | `auto`, `register`, `extern`, `static`, `thread_local` |
| [06_tentative_definitions.c](06_tentative_definitions.c) | Several declarations, one definition |
| [07_lifetime.c](07_lifetime.c) | When a pointer into an object becomes unusable |
| [08_register_address.c](08_register_address.c) | `&` on a `register` object must not compile |
| [09_external_linkage/](09_external_linkage/) | One definition, two translation units |

## The four scopes

| Scope | Holds | Visible |
|---|---|---|
| File | Functions, file-scope objects, typedefs | From the declaration to the end of the file |
| Block | Objects, typedefs, further declarations | From the declaration to the end of the block |
| Function prototype | Parameter names in a non-defining declaration | The prototype only |
| Function | Labels | The whole function |

## Key points

- A nested declaration hides the outer name. It does not destroy the outer object.
- `static` at file scope is internal linkage. `static` in a block is storage duration. The word is doing two jobs.
- `thread_local` may be combined with `static` or `extern`. No other pair of storage-class specifiers may.
- Tentative definitions are a per-file rule. Two initialized definitions in two files are a link error.
- The lifetime of an automatic object ends when its block ends, even if you kept the address.

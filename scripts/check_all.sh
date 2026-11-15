#!/usr/bin/env bash
# Compile and run every example, honouring the @directives in CONVENTIONS.md.
# Warnings are errors here: an example that warns on purpose says so with
# "// @flags -Wno-error".
# Usage: scripts/check_all.sh [chapter-dir...]     (default: all chapters)
#        CC=clang scripts/check_all.sh             (another compiler)
#        SAN=1 scripts/check_all.sh                (under the sanitizers)
set -uo pipefail
source "$(dirname "${BASH_SOURCE[0]}")/common.sh"
shopt -s nullglob

pass=0
fail=0
skip=0
failures=()

ok()   { pass=$((pass + 1)); printf 'PASS  %s\n' "$1"; }
bad()  { fail=$((fail + 1)); failures+=("$1"); printf 'FAIL  %s  (%s)\n' "$1" "$2"; }
skipped() { skip=$((skip + 1)); printf 'SKIP  %s  (%s)\n' "$1" "$2"; }

if [[ $# -gt 0 ]]; then
  chapters=("$@")
else
  chapters=("$root"/[0-9][0-9]-*/)
fi

log="$(mktemp)"
trap 'rm -f "$log"' EXIT

for chapter in "${chapters[@]}"; do
  chapter="$(realpath "$chapter")"

  for src in "$chapter"/*.c; do
    rel="${src#"$root"/}"
    mode="$(directive build "$src")"

    reason="$(skip_reason "$src")"
    if [[ -n $reason ]]; then
      skipped "$rel" "$reason"
      continue
    fi

    if ! exe="$(build_one "$src" -Werror 2>"$log")"; then
      if [[ $mode == fail* ]]; then ok "$rel"; else bad "$rel" "compile error"; cat "$log"; fi
      continue
    fi
    if [[ $mode == fail* ]]; then
      bad "$rel" "compiled but was expected to fail"
      continue
    fi
    if [[ "$(directive run "$src")" == no* ]]; then
      ok "$rel"
      continue
    fi

    expected="$(directive exit "$src")"
    timeout 20 bash -c 'source "$0/scripts/common.sh"; run_one "$1" "$2"' \
      "$root" "$exe" "$src" >"$log" 2>&1
    status=$?
    if [[ $SAN == 1 && "$(directive san "$src")" == fail* ]]; then
      if [[ $status -ne 0 ]]; then ok "$rel"; else bad "$rel" "the sanitizers were expected to stop it"; fi
    elif [[ $status -eq ${expected:-0} ]]; then
      ok "$rel"
    else
      bad "$rel" "exit status $status, expected ${expected:-0}"
      tail -n 20 "$log"
    fi
  done

  for script in "$chapter"/*/build.sh; do
    dir="$(dirname "$script")"
    rel="${dir#"$root"/}/"
    OUT="$BUILD_DIR/${dir#"$root"/}"
    rm -rf "$OUT" && mkdir -p "$OUT"
    (cd "$dir" && CC="$CC" CFLAGS="$SCRIPT_CFLAGS -Werror" LDLIBS="$LDLIBS" OUT="$OUT" \
      timeout 120 bash "$script") </dev/null >"$log" 2>&1
    status=$?
    if [[ $status -eq 0 ]]; then
      ok "$rel"
    elif [[ $status -eq 77 ]]; then
      skipped "$rel" "$(tail -n 1 "$log")"
    else
      bad "$rel" "build.sh failed"
      tail -n 20 "$log"
    fi
  done
done

printf '\n%d passed, %d failed, %d skipped\n' "$pass" "$fail" "$skip"
if [[ $fail -gt 0 ]]; then
  printf 'failed: %s\n' "${failures[@]}"
  exit 1
fi

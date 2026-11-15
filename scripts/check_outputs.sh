#!/usr/bin/env bash
# Rebuild every example that documents its output in a "// Output:" block,
# run it, and report any difference from the documented text.
# Usage: scripts/check_outputs.sh [chapter-dir...]
#        CC=clang scripts/check_outputs.sh
#        CFLAGS="-std=c23 -O2" scripts/check_outputs.sh   (any flags)
set -uo pipefail
source "$(dirname "${BASH_SOURCE[0]}")/common.sh"
shopt -s nullglob

if [[ $# -gt 0 ]]; then chapters=("$@"); else chapters=("$root"/[0-9][0-9]-*/); fi

same=0
different=0
for chapter in "${chapters[@]}"; do
  for src in "$chapter"/*.c; do
    grep -q '^// Output:' "$src" || continue
    [[ -n "$(skip_reason "$src")" ]] && continue
    rel="$(realpath --relative-to="$root" "$src")"
    if ! exe="$(build_one "$src" 2>/dev/null)"; then
      different=$((different + 1)); printf 'BUILD FAIL  %s\n' "$rel"; continue
    fi
    actual="$(timeout 30 bash -c 'source "$0/scripts/common.sh"; run_one "$1" "$2"' \
      "$root" "$exe" "$src" 2>/dev/null | sed -e 's/[[:space:]]*$//')"
    expected="$(sed -n '/^\/\/ Output:/,$p' "$src" | tail -n +2 | sed -e 's|^// ||' -e 's|^//$||')"
    if [[ $actual == "$expected" ]]; then
      same=$((same + 1))
    else
      different=$((different + 1))
      printf 'DIFF  %s\n' "$rel"
      diff <(printf '%s\n' "$expected") <(printf '%s\n' "$actual") | head -n 10
    fi
  done
done

printf '\n%d outputs identical, %d different\n' "$same" "$different"
[[ $different -eq 0 ]]

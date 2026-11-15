# Shared settings for the other scripts. Source, don't execute.

root="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"

CC="${CC:-gcc}"
CFLAGS="${CFLAGS:--std=c23 -Wall -Wextra -pedantic -g}"
LDLIBS="${LDLIBS:--lm}"
BUILD_DIR="${BUILD_DIR:-$root/build}"

# SAN=1 adds the address and undefined-behaviour sanitizers. A report from
# either one ends the program with a non-zero status.
SAN="${SAN:-0}"
if [[ $SAN == 1 ]]; then
  CFLAGS="$CFLAGS -fsanitize=address,undefined -fno-sanitize-recover=all -fno-omit-frame-pointer"
fi

# compiler_family: gcc or clang, whatever the executable is called.
compiler_family() {
  if "$CC" --version 2>/dev/null | grep -qi clang; then echo clang; else echo gcc; fi
}

# SCRIPT_CFLAGS is what a build.sh receives. Such a script passes the same
# flags to compile-only and link-only commands; clang warns about the flags
# a given command has no use for, which is noise there.
SCRIPT_CFLAGS="$CFLAGS"
if [[ "$(compiler_family)" == clang ]]; then
  SCRIPT_CFLAGS="$CFLAGS -Wno-unused-command-line-argument"
fi

# directive KEY FILE: print the value of the first "// @KEY value" line, if any.
directive() {
  sed -n "s|^[[:space:]]*//[[:space:]]*@$1[[:space:]]*||p" "$2" | head -n 1
}

# skip_reason FILE: print why FILE is not built in this configuration, if so.
skip_reason() {
  local mode only san
  mode="$(directive build "$1")"
  if [[ $mode == skip* ]]; then echo "${mode#skip }"; return; fi
  only="$(directive only "$1")"
  if [[ -n $only && ${only%% *} != "$(compiler_family)" ]]; then
    echo "${only%% *} only: ${only#* }"; return
  fi
  san="$(directive san "$1")"
  if [[ $SAN == 1 && $san == skip* ]]; then echo "sanitizers: ${san#skip }"; fi
}

# build_one FILE [extra flags...]: compile FILE into its own build directory
# and print the path of the executable.
build_one() {
  local src rel out
  src="$(realpath "$1")"
  shift
  rel="${src#"$root"/}"
  out="$BUILD_DIR/${rel%.*}"
  mkdir -p "$out"
  # shellcheck disable=SC2086,SC2046
  "$CC" $CFLAGS "$@" $(directive flags "$src") "$src" -o "$out/a.out" $LDLIBS $(directive libs "$src") >&2 || return
  echo "$out/a.out"
}

# run_one EXE FILE: run EXE with the arguments and standard input that FILE
# asks for through its @args and @stdin directives.
run_one() {
  local exe="$1" src="$2" input
  input="$(directive stdin "$src")"
  # shellcheck disable=SC2046
  if [[ -n $input ]]; then
    printf '%b' "$input" | "$exe" $(directive args "$src")
  else
    "$exe" $(directive args "$src") </dev/null
  fi
}

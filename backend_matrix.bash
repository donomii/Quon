#!/bin/bash
set -euo pipefail

ROOT="$(cd "$(dirname "$0")" && pwd)"
OUTDIR=""
PROGRAMS=()

BACKENDS=(c perl java node)
TARGETS=(ansi3 perl java node2)
TARGET_FLAGS=(--ansi3 --perl --java --node2)
TARGET_EXTS=(c pl java js)

DIFFS=0
MATCH_MARK="√"
CELL_WIDTH=12

usage() {
  cat <<USAGE
Usage: $0 [--outdir DIR] [program.qon ...]

Compiles each check program with every live bootstrap backend, writes every
generated target backend to DIR, and prints pairwise comparison matrices.
For compiler.qon, generated compiler outputs are also run with --test.
For other programs, generated outputs are syntax/build checked but not run.

If no check program is provided, compiler.qon is checked.
USAGE
}

while [ "$#" -gt 0 ]; do
  case "$1" in
    -h|--help)
      usage
      exit 0
      ;;
    --outdir)
      if [ "$#" -lt 2 ]; then
        echo "--outdir requires a directory" >&2
        exit 2
      fi
      OUTDIR="$2"
      shift 2
      ;;
    --)
      shift
      while [ "$#" -gt 0 ]; do
        PROGRAMS+=("$1")
        shift
      done
      ;;
    -*)
      echo "Unknown option: $1" >&2
      usage >&2
      exit 2
      ;;
    *)
      PROGRAMS+=("$1")
      shift
      ;;
  esac
done

if [ "${#PROGRAMS[@]}" -eq 0 ]; then
  PROGRAMS=(compiler.qon)
fi

if [ -z "$OUTDIR" ]; then
  OUTDIR="${TMPDIR:-/private/tmp}/quon-backend-matrix-$(date +%Y%m%d-%H%M%S)"
fi

mkdir -p "$OUTDIR"
LOGDIR="$OUTDIR/logs"
mkdir -p "$LOGDIR"

slugify() {
  printf '%s' "$(basename "$1")" | tr -c 'A-Za-z0-9._-' '_'
}

is_compiler_program() {
  [ "$(basename "$1")" = "compiler.qon" ]
}

run_logged() {
  label="$1"
  log="$2"
  shift 2

  printf "%-64s" "$label"
  if "$@" >"$log" 2>&1; then
    printf "PASS\n"
  else
    printf "FAIL\n"
    echo "Log: $log" >&2
    sed -n '1,160p' "$log" >&2
    return 1
  fi
}

run_logged_root() {
  label="$1"
  log="$2"
  shift 2

  printf "%-64s" "$label"
  if (cd "$ROOT" && "$@") >"$log" 2>&1; then
    printf "PASS\n"
  else
    printf "FAIL\n"
    echo "Log: $log" >&2
    sed -n '1,160p' "$log" >&2
    return 1
  fi
}

print_cell() {
  text="$1"
  width="$CELL_WIDTH"
  len="${#text}"
  left=$(((width - len) / 2))
  right=$((width - len - left))
  printf "%*s%s%*s" "$left" "" "$text" "$right" ""
}

run_logged_quiet() {
  label="$1"
  log="$2"
  shift 2

  if "$@" >"$log" 2>&1; then
    return 0
  else
    printf "%-64sFAIL\n" "$label"
    echo "Log: $log" >&2
    sed -n '1,160p' "$log" >&2
    return 1
  fi
}

prepare_java_bootstrap() {
  JAVA_CLASSES="$OUTDIR/java-bootstrap-classes"
  mkdir -p "$JAVA_CLASSES"
  run_logged "javac bootstrap/quon.java" "$LOGDIR/java-bootstrap-javac.log" \
    javac -d "$JAVA_CLASSES" "$ROOT/bootstrap/quon.java"
}

prepare_c_bootstrap() {
  C_BOOTSTRAP="$OUTDIR/c-bootstrap"
  run_logged "gcc bootstrap/quon.c" "$LOGDIR/c-bootstrap-gcc.log" \
    gcc -O2 -Wno-parentheses-equality -Wno-format-security "$ROOT/bootstrap/quon.c" -o "$C_BOOTSTRAP"
}

backend_run() {
  backend="$1"
  shift

  case "$backend" in
    c)
      "$C_BOOTSTRAP" "$@"
      ;;
    perl)
      perl bootstrap/quon.pl "$@"
      ;;
    java)
      java -Xss100M -cp "$JAVA_CLASSES" QuonProgram "$@"
      ;;
    node)
      node bootstrap/quon.js "$@"
      ;;
    *)
      echo "Unknown backend: $backend" >&2
      exit 2
      ;;
  esac
}

emit_artifact() {
  backend="$1"
  program="$2"
  flag="$3"
  artifact="$4"
  log="$5"

  printf "%-64s" "emit $backend $program $flag"
  if (cd "$ROOT" && backend_run "$backend" "$program" "$flag" >"$artifact") 2>"$log"; then
    printf "PASS\n"
  else
    printf "FAIL\n"
    echo "Log: $log" >&2
    sed -n '1,160p' "$log" >&2
    return 1
  fi
}

verify_artifact() {
  backend="$1"
  target="$2"
  artifact="$3"
  program="$4"
  target_dir="$5"

  case "$target" in
    ansi3)
      binary="$target_dir/$backend.bin"
      run_logged_quiet "gcc $backend -> $target" "$target_dir/$backend.gcc.log" \
        gcc -O2 -Wno-parentheses-equality -Wno-format-security "$artifact" -o "$binary"
      if is_compiler_program "$program"; then
        run_logged_quiet "$backend -> $target --test" "$target_dir/$backend.test.log" "$binary" --test
      fi
      ;;
    perl)
      run_logged_quiet "perl -c $backend -> $target" "$target_dir/$backend.perl-check.log" \
        perl -c "$artifact"
      if is_compiler_program "$program"; then
        run_logged_quiet "$backend -> $target --test" "$target_dir/$backend.test.log" perl "$artifact" --test
      fi
      ;;
    java)
      classes="$target_dir/$backend.classes"
      mkdir -p "$classes"
      run_logged_quiet "javac $backend -> $target" "$target_dir/$backend.javac.log" \
        javac -d "$classes" "$artifact"
      if is_compiler_program "$program"; then
        run_logged_quiet "$backend -> $target --test" "$target_dir/$backend.test.log" \
          java -Xss100M -cp "$classes" QuonProgram --test
      fi
      ;;
    node2)
      run_logged_quiet "node --check $backend -> $target" "$target_dir/$backend.node-check.log" \
        node --check "$artifact"
      if is_compiler_program "$program"; then
        run_logged_quiet "$backend -> $target --test" "$target_dir/$backend.test.log" node "$artifact" --test
      fi
      ;;
    *)
      echo "Unknown target: $target" >&2
      exit 2
      ;;
  esac
}

compare_target() {
  program="$1"
  target="$2"
  ext="$3"
  target_dir="$4"

  printf "\nComparison matrix: %s -> %s\n" "$program" "$target"
  printf "%${CELL_WIDTH}s" ""
  for col in "${BACKENDS[@]}"; do
    print_cell "$col"
  done
  printf "\n"

  for row in "${BACKENDS[@]}"; do
    printf "%${CELL_WIDTH}s" "$row"
    row_file="$target_dir/$row.$ext"
    for col in "${BACKENDS[@]}"; do
      col_file="$target_dir/$col.$ext"
      if [ "$row" = "$col" ]; then
        print_cell "-"
      elif cmp -s "$row_file" "$col_file"; then
        print_cell "$MATCH_MARK"
      else
        print_cell "DIFF"
        DIFFS=1
      fi
    done
    printf "\n"
  done
}

check_bootstraps() {
  printf "\nBootstrap checks\n"
  for backend in "${BACKENDS[@]}"; do
    run_logged_root "$backend bootstrap --test" "$LOGDIR/$backend-bootstrap-test.log" \
      backend_run "$backend" --test
  done
}

check_program() {
  program="$1"
  program_slug="$(slugify "$program")"
  program_dir="$OUTDIR/$program_slug"
  mkdir -p "$program_dir"

  printf "\nCheck program: %s\n" "$program"
  printf "Artifacts: %s\n" "$program_dir"

  for i in "${!TARGETS[@]}"; do
    target="${TARGETS[$i]}"
    flag="${TARGET_FLAGS[$i]}"
    ext="${TARGET_EXTS[$i]}"
    target_dir="$program_dir/$target"
    mkdir -p "$target_dir"

    printf "\nTarget: %s (%s)\n" "$target" "$flag"
    for backend in "${BACKENDS[@]}"; do
      artifact="$target_dir/$backend.$ext"
      emit_artifact "$backend" "$program" "$flag" "$artifact" "$target_dir/$backend.emit.log"
    done

    compare_target "$program" "$target" "$ext" "$target_dir"

    for backend in "${BACKENDS[@]}"; do
      artifact="$target_dir/$backend.$ext"
      verify_artifact "$backend" "$target" "$artifact" "$program" "$target_dir"
    done
  done
}

printf "Output directory: %s\n" "$OUTDIR"
prepare_c_bootstrap
prepare_java_bootstrap
check_bootstraps

for program in "${PROGRAMS[@]}"; do
  check_program "$program"
done

if [ "$DIFFS" -ne 0 ]; then
  printf "\nBackend matrix found output differences. Artifacts are in %s\n" "$OUTDIR" >&2
  exit 1
fi

printf "\nBackend matrix passed. Artifacts are in %s\n" "$OUTDIR"

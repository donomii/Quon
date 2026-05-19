#!/bin/bash
set -euo pipefail

ROOT="$(cd "$(dirname "$0")" && pwd)"
OUTDIR=""
PROGRAMS=()

usage() {
  cat <<USAGE
Usage: $0 [--outdir DIR] [program.qon ...]

Runs the parser negative tests and the backend matrix. If no programs are
provided, the compiler and current example programs are checked.
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

if [ -z "$OUTDIR" ]; then
  OUTDIR="${TMPDIR:-/private/tmp}/quon-check-$(date +%Y%m%d-%H%M%S)"
fi

if [ "${#PROGRAMS[@]}" -eq 0 ]; then
  PROGRAMS=(
    compiler.qon
    examples/hello.qon
    examples/fac.qon
    examples/quotelist.qon
    examples/lib/portable_libs.qon
    examples/mandelbrot.qon
    listtest.qon
  )
fi

mkdir -p "$OUTDIR"

printf "Check output directory: %s\n" "$OUTDIR"

printf "\nParser negative tests\n"
"$ROOT/parser_negative_tests.bash" --outdir "$OUTDIR/parser-negative"

printf "\nImaginary front-end tests\n"
"$ROOT/imaginary_tests.bash" --outdir "$OUTDIR/imaginary"

printf "\nBackend matrix\n"
"$ROOT/backend_matrix.bash" --outdir "$OUTDIR/backend-matrix" "${PROGRAMS[@]}"

printf "\nAll checks passed. Logs and artifacts are in %s\n" "$OUTDIR"

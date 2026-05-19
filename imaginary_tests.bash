#!/bin/bash
set -euo pipefail

ROOT="$(cd "$(dirname "$0")" && pwd)"
OUTDIR=""

usage() {
  cat <<USAGE
Usage: $0 [--outdir DIR]

Runs smoke tests for the Imaginary front end. The tests convert .ima programs
to Quon, compile them through the current Node bootstrap, run the generated
programs, and check expected output.
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
    *)
      echo "Unknown option: $1" >&2
      usage >&2
      exit 2
      ;;
  esac
done

if [ -z "$OUTDIR" ]; then
  OUTDIR="${TMPDIR:-/private/tmp}/quon-imaginary-$(date +%Y%m%d-%H%M%S)"
fi

LOGDIR="$OUTDIR/logs"
ARTIFACTDIR="$OUTDIR/artifacts"
mkdir -p "$LOGDIR" "$ARTIFACTDIR"

run_logged() {
  label="$1"
  log="$2"
  shift 2

  printf "%-48s" "$label"
  if "$@" >"$log" 2>&1; then
    printf "PASS\n"
  else
    printf "FAIL\n"
    echo "Log: $log" >&2
    sed -n '1,160p' "$log" >&2
    return 1
  fi
}

write_expected() {
  name="$1"
  shift

  expected="$ARTIFACTDIR/$name.expected"
  : >"$expected"
  for line in "$@"; do
    printf "%s\n" "$line" >>"$expected"
  done
}

run_case() {
  name="$1"
  source="$2"
  shift 2

  qon="$ARTIFACTDIR/$name.qon"
  js="$ARTIFACTDIR/$name.js"
  stdout="$ARTIFACTDIR/$name.stdout"
  expected="$ARTIFACTDIR/$name.expected"

  write_expected "$name" "$@"

  run_logged "imaginary convert $name" "$LOGDIR/$name-convert.log" \
    node "$ROOT/ima/imaginary.js" "$ROOT/$source"
  node "$ROOT/ima/imaginary.js" "$ROOT/$source" >"$qon" 2>"$LOGDIR/$name-convert-artifact.log"

  run_logged "imaginary direct compile $name" "$LOGDIR/$name-direct-compile.log" \
    node "$ROOT/ima/imaginary.js" "$ROOT/$source" --node2
  node "$ROOT/ima/imaginary.js" "$ROOT/$source" --node2 >"$js" 2>"$LOGDIR/$name-direct-artifact.log"

  run_logged "node syntax $name" "$LOGDIR/$name-node-check.log" \
    node --check "$js"

  run_logged "node run $name" "$LOGDIR/$name-run.log" \
    node "$js"
  node "$js" >"$stdout" 2>"$LOGDIR/$name-run-artifact.log"

  run_logged "stdout compare $name" "$LOGDIR/$name-diff.log" \
    diff -u "$expected" "$stdout"
}

run_negative_case() {
  bad="$ARTIFACTDIR/bad.ima"
  log="$LOGDIR/bad.log"
  printf "nope\n" >"$bad"

  printf "%-48s" "imaginary rejects bad input"
  if node "$ROOT/ima/imaginary.js" "$bad" >"$ARTIFACTDIR/bad.qon" 2>"$log"; then
    printf "FAIL\n"
    echo "Expected Imaginary parse failure" >&2
    return 1
  fi

  if grep -Fq "expected Includes" "$log"; then
    printf "PASS\n"
  else
    printf "FAIL\n"
    sed -n '1,160p' "$log" >&2
    return 1
  fi
}

run_playground_harness() {
  run_logged "playground imaginary docs" "$LOGDIR/playground-docs.log" \
    node "$ROOT/web/playground_imaginary_test.mjs"
}

run_logged "node syntax imaginary.js" "$LOGDIR/imaginary-js-check.log" \
  node --check "$ROOT/ima/imaginary.js"
run_logged "node syntax playground.js" "$LOGDIR/playground-js-check.log" \
  node --check "$ROOT/web/playground.js"
run_logged "node syntax source-bundle.js" "$LOGDIR/source-bundle-check.log" \
  node --check "$ROOT/web/source-bundle.js"

run_case hello ima/hello.ima "Hello World from Ima"
run_case factorial ima/pairsum.ima \
  "Factorial 0: 1" \
  "Factorial 1: 1" \
  "Factorial 2: 2" \
  "Factorial 3: 6" \
  "Factorial 10: 3628800"
run_negative_case
run_playground_harness

echo "Imaginary tests wrote logs to $OUTDIR"

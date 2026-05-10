#!/bin/bash
set -euo pipefail

ROOT="$(cd "$(dirname "$0")" && pwd)"
OUTDIR="${TMPDIR:-/private/tmp}/quon-parser-negative-$(date +%Y%m%d-%H%M%S)"
CASEDIR="$OUTDIR/cases"
LOGDIR="$OUTDIR/logs"
COMPILER="$OUTDIR/quon"

mkdir -p "$CASEDIR" "$LOGDIR"

gcc -O2 -Wno-parentheses-equality -Wno-format-security \
  "$ROOT/bootstrap/quon.c" \
  -o "$COMPILER"

write_case() {
  name="$1"
  shift

  file="$CASEDIR/$name.qon"
  : >"$file"
  for line in "$@"; do
    printf "%s\n" "$line" >>"$file"
  done
}

expect_pass() {
  name="$1"
  log="$LOGDIR/$name.log"

  if "$COMPILER" "$CASEDIR/$name.qon" --tree >"$log" 2>&1; then
    printf "%-32s PASS\n" "$name"
  else
    printf "%-32s FAIL\n" "$name"
    sed -n '1,120p' "$log" >&2
    return 1
  fi
}

expect_fail() {
  name="$1"
  expected="$2"
  log="$LOGDIR/$name.log"

  if "$COMPILER" "$CASEDIR/$name.qon" --tree >"$log" 2>&1; then
    printf "%-32s FAIL\n" "$name"
    echo "Expected parse failure containing: $expected" >&2
    return 1
  fi

  if grep -Fq "$expected" "$log"; then
    printf "%-32s PASS\n" "$name"
  else
    printf "%-32s FAIL\n" "$name"
    echo "Expected parse failure containing: $expected" >&2
    sed -n '1,120p' "$log" >&2
    return 1
  fi
}

write_case valid-minimal \
  "((includes) (types) (functions (int start () (declare) (body (return 0)))))"

write_case missing-close \
  "((includes)" \
  " (types)" \
  " (functions"

write_case unexpected-close \
  "((includes) (types) (functions)) )"

write_case extra-top-level \
  "((includes) (types) (functions))" \
  "((includes) (types) (functions))"

write_case missing-section \
  "((includes) (types))"

write_case invalid-function \
  "((includes) (types) (functions (int start () (declare))))"

write_case if-missing-else \
  "((includes) (types) (functions (int start () (declare) (body (if true (then (return 0)))))))"

write_case if-bad-else-name \
  "((includes) (types) (functions (int start () (declare) (body (if true (then (return 0)) (otherwise (return 1)))))))"

write_case then-outside-if \
  "((includes) (types) (functions (int start () (declare) (body (then (return 0))))))"

write_case else-outside-if \
  "((includes) (types) (functions (int start () (declare) (body (else (return 0))))))"

write_case bad-return \
  "((includes) (types) (functions (int start () (declare) (body (return 1 2)))))"

write_case bad-set \
  "((includes) (types) (functions (int start () (declare) (body (set x)))))"

write_case bad-set-struct \
  "((includes) (types) (functions (int start () (declare) (body (set-struct x y)))))"

write_case nested-function-body \
  "((includes)" \
  " (types)" \
  " (functions" \
  "  (int start () (declare)" \
  "   (body" \
  "    (int inner () (declare) (body (return 0)))" \
  "    (return 0)))))"

write_case nested-function-expression \
  "((includes) (types) (functions (int start () (declare) (body (return (int inner () (declare) (body (return 0))))))))"

write_case body-inside-expression \
  "((includes) (types) (functions (int start () (declare) (body (return (body (return 0)))))))"

expect_pass valid-minimal
expect_fail missing-close "missing ')'"
expect_fail unexpected-close "unexpected ')'"
expect_fail extra-top-level "extra top-level form after program"
expect_fail missing-section "program must contain includes, types, and functions sections"
expect_fail invalid-function "invalid function definition"
expect_fail if-missing-else "if must contain condition, then, and else"
expect_fail if-bad-else-name "expected else"
expect_fail then-outside-if "then branch outside if"
expect_fail else-outside-if "else branch outside if"
expect_fail bad-return "return takes zero or one value"
expect_fail bad-set "set takes a target and value"
expect_fail bad-set-struct "set-struct takes a target, field, and value"
expect_fail nested-function-body "function definition nested inside body"
expect_fail nested-function-expression "function definition nested inside expression"
expect_fail body-inside-expression "body block inside expression"

echo "Parser negative tests wrote logs to $OUTDIR"

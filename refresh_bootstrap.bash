#!/bin/bash
set -euo pipefail

COMPILER="./build/quon_new"
OUTDIR="${TMPDIR:-/private/tmp}/quon-refresh-bootstrap-$(date +%Y%m%d-%H%M%S)"

if [ ! -x "$COMPILER" ]; then
  COMPILER="./build/quon"
fi

if [ ! -x "$COMPILER" ]; then
  echo "No compiler found at ./build/quon_new or ./build/quon" >&2
  exit 1
fi

mkdir -p "$OUTDIR"

"$COMPILER" compiler.qon --ansi3 > "$OUTDIR/quon-stage.c"
gcc -O2 -Wno-parentheses-equality -Wno-format-security "$OUTDIR/quon-stage.c" -o "$OUTDIR/quon-stage"

"$OUTDIR/quon-stage" compiler.qon --ansi3 > "$OUTDIR/quon.c"
"$OUTDIR/quon-stage" compiler.qon --node > "$OUTDIR/quon.js"
"$OUTDIR/quon-stage" compiler.qon --perl > "$OUTDIR/quon.pl"
"$OUTDIR/quon-stage" compiler.qon --java > "$OUTDIR/quon.java"

mv "$OUTDIR/quon.c" bootstrap/quon.c
mv "$OUTDIR/quon.js" bootstrap/quon.js
mv "$OUTDIR/quon.pl" bootstrap/quon.pl
mv "$OUTDIR/quon.java" bootstrap/quon.java

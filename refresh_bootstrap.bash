#!/bin/bash
set -euo pipefail

OUTDIR="${TMPDIR:-/private/tmp}/quon-refresh-bootstrap-$(date +%Y%m%d-%H%M%S)"

mkdir -p "$OUTDIR"

gcc -O2 -Wno-parentheses-equality -Wno-format-security bootstrap/quon.c -o "$OUTDIR/quon-seed"
"$OUTDIR/quon-seed" compiler.qon --ansi3 > "$OUTDIR/quon-stage.c"
gcc -O2 -Wno-parentheses-equality -Wno-format-security "$OUTDIR/quon-stage.c" -o "$OUTDIR/quon-stage"

"$OUTDIR/quon-stage" compiler.qon --ansi3 > "$OUTDIR/quon.c"
"$OUTDIR/quon-stage" compiler.qon --node > "$OUTDIR/quon.js"
"$OUTDIR/quon-stage" compiler.qon --perl > "$OUTDIR/quon.pl"
"$OUTDIR/quon-stage" compiler.qon --java > "$OUTDIR/quon.java"

mv "$OUTDIR/quon.c" bootstrap/quon.c
mv "$OUTDIR/quon.js" bootstrap/quon.js
mv "$OUTDIR/quon.pl" bootstrap/quon.pl
mv "$OUTDIR/quon.java" bootstrap/quon.java

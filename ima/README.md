Imaginary is an old experimental front end for Quon.  It parses a small
C/Pascal-ish syntax and emits normal Quon s-expressions, so the existing Quon
compiler and backends still do the real work.

Example:

    node ima/imaginary.js ima/hello.ima > /tmp/hello.qon
    node bootstrap/quon.js /tmp/hello.qon --node2 > /tmp/hello.js
    node /tmp/hello.js

Or compile directly through the current Node bootstrap:

    node ima/imaginary.js ima/hello.ima --node2 > /tmp/hello.js

Current shape:

- `Includes:`, `Types:`, and `Functions:` sections map to the usual Quon
  sections.
- Functions use `fu name(arg: type) -> returnType ... in ... end function`.
- Calls use `name(arg1, arg2);`.
- Assignments use `name = expression;`.
- Conditionals use `if expr then ... else ... end`.
- Local declarations go before `in` as `name: type initialValue`.

This is still only a prototype.  `imaginary.js` is the current converter and
can run in Node or in the browser playground.  `imaparse.pl` is the older
`Parse::RecDescent` version kept around for comparison.  Neither converter
preserves source locations into the generated Quon tree yet.

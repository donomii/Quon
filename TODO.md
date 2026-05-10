# TODO

Captured May 9, 2026.

## Runtime And Embedding

- Add some kind of `eval`.
  - C can parse and run Quon functions, then use a dynamic loader for native pieces.
  - Perl and JavaScript should be straightforward here.
- Build an interactive webpage so people can play with the language.
- Consider embedding the compiler source into the compiler so it can regenerate itself anywhere.
- Think about an MCP interface.

## Language Shape

- Design an alternate input language that is not a horror show.
- Add the keyword `function` to the start of each function definition so definitions are easy to grep.
- Rename awkward constructs like `ternlist` and `chooseBox`.
- Make the language easier to change.
- Harden the parser so malformed forms error and quit properly instead of being passed to backends as strange trees.
- Fix import/module resolution.
  - Today, the top-level program has to import every library and sub-library directly, or the build fails.
  - Handle modules importing their own libraries, either with a pre-pass that gathers the full import closure or by patching the program tree as imports are encountered.
  - This may need real modules and namespaces first.

## Backends

- Fix `--release --ansi3`: release mode suppresses stack trace pushes but still emits `StackTraceMove("out", ...)`, which can call `cdr` on an empty trace stack.
- Finish making the C outputter return strings/lists instead of printing directly.
- Keep improving the JavaScript outputter as the main webpage/library target.
- Decide whether Java is still worth reviving after C and JavaScript are solid.
- Consider a .NET backend for broader platform coverage.
- Maybe eventually make outputters for everything, after the language settles.

## Tests

- Build a real test runner that can compile and run fixture programs across C, Perl, and Node.
- Add regression tests for parser failures, especially missing/extra parentheses and swallowed function definitions.
- Add regression coverage for `--release --ansi3`.

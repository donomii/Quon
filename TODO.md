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

## Backends

- Finish making the C outputter return strings/lists instead of printing directly.
- Keep improving the JavaScript outputter as the main webpage/library target.
- Decide whether Java is still worth reviving after C and JavaScript are solid.
- Consider a .NET backend for broader platform coverage.
- Maybe eventually make outputters for everything, after the language settles.

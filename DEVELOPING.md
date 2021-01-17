= Developers guide

Quon is made for you to alter and improve to suit your needs.  This guide will get you started as quickly and easily as possible.

== The goal

The goal of quon is to be a self hosting language that can run really anywhere.  Unlike gcc or perl, which require an army of volunteers to support all their platforms, quon is designed to swing from platform to platform with the greatest of ease.  Possibly I should call it "Trapeze".

Quon does this, in part, by relying on GCC and other languages to handle part of the compilation.  Quon does not, and probably never will generate machine code, but outputting assembler code is a long term goal.

== Principles

The underlying principle of quon is to be simple and only use common features of programming languages.  Eventually it will gain some more powerful features, but for now it is simple and generally inflexible.

So rather than having a complicated parser like RecDescent or Combinator, it uses simple if statements to parse a token stream.  So there is no flexibility, but on the up side, it is simple and fast.

== The files

compiler.qon is the command line frontend to start the compiler

base.qon Holds all the parsing and lexing code.  The parser is a simple S-Expression reader (written in qon), and so the language looks very lisp-like even though it isn't a lisp at all.

perl.qon, c.qon, node.qon, java.qon hold the output generators for each language.  They take the AST generated in base.qon, and generate correct code for their target language.

== The compiler

The compiler is very simple.  It parses the input into an s-expression, does some extremely simple transforms on it, builds an AST, then walks the AST to print out code in the target language.

This is technically a multi-pass compiler.  The source code is loaded into memory, and a single AST is created in memory.  This process is inefficient, and wastes a lot of memory.

== The language

The language is made of the common features that I could identify among modern programming languages.  So it does not support objects, first class functions, closures, inheritence, or other popular language features.  In general, you can define functions and call them, and define data structures and access them.

The payoff to this limition is that you can convert your code into 4 different languages, and there are more on the way.

== The AST

The AST is a direct reflection of the code.  Additional data for compilation is stored in "tags".  Tags are hash tables that are "attached" to other data.  At the moment, this only works for boxes.  So an AST node would just be a symbol, with the followng tags attached

        ("line"    -1)              Line number of source file, deprecated
        ("file"    base)              Line number of source file, deprecated
        ("name"    "node type")     e.g. statement, expression
        ("subname" "subtype")       node subtype, e.g. setter, getter


Specialised nodes often have more keys.  

Function:
    intype, outtype     The type signature for the function
    declarations        A list of variable for the function, same format as the types section
    statements


Types

Types are not currently checked.  Quon simply believes you when you use a type, and if it is wrong, you will get an error from the target language.  Type checking and inference is planned.

Structs

Structs are fully supported.  You can define structs made of structs, and access and set members.
    




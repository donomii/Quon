= Developers guide

Quon is made for you to alter and improve to suit your needs.  This guide will get you started as quickly and easily as possible.

== The goal

The goal of quon is to be a self hosting language that can run really anywhere.  quon is designed to swing from platform to platform with the greatest of ease.  Possibly I should call it "Trapeze".

Quon does this, in part, by relying on GCC and other languages to handle part of the compilation.  Quon does not, and probably never will generate machine code, but outputting assembler code is a long term goal.

Quon's main trick is changing to adapt to the target platform.  It is just barely capable of handling enough strings and numbers to do this.  It doesn't have any idea of memory layouts or platform specific features, it hands that off to the target language.  As a result, only the simplest structure definitions are likely to work across platforms.

== Principles

The underlying principle of quon is to be simple and only use common features of programming languages.  Eventually it will gain some more powerful features, but for now it is simple and generally inflexible.

So rather than having a complicated parser like RecDescent or Combinator, it uses simple if statements to parse a token stream.  So there is no flexibility, but on the up side, it is simple and fast.

== The files

compiler.qon is the compiler source.

base.qon Holds all the parsing and lexing code.  The parser is a simple S-Expression reader (written in qon), and so the language looks very lisp-like even though it isn't a lisp at all.

perl.qon, c.qon, node.qon, java.qon hold the output generators for each language.  They take the AST generated in base.qon, and generate correct code for their target language.

== The compiler

The compiler is very simple.  It parses the input as s-expressions, does some extremely simple transforms on it, builds an AST, then walks the AST to print out code in the target language.

This is technically a multi-pass compiler.  The entire source code, including all libraries is loaded into memory, and a single AST is created in memory.  This process is inefficient, and wastes a lot of memory.  There is no garbage collector, so if the target language doesn't have one, then quon will usually run out of memory and crash.

== Compiling

Start with 

	bash bootstrap.bash

which will build an operation compiler from the source files in bootstrap/ .

Next, make some changes and run

	bash build.bash

This will build and test the compiler.

Development usually involves running circular.bash.  circular will compile your code into the next version of the compiler, then compile your source code again, using the next version of the compiler. 

	bash circular.bash

This is needed because it is too easy to modify the source so much that it can still be compiled with the current version of quon, but is unable to compile itself (generate new versions).

== Controlling the compiler

	quon -h

lists the possible switches.  Most of them are for choosing the target platform, the rest provide useful debugging features:

	--trace			Print each function as it is called
	--steptrace		Print every line as it is run
	--release		Compile without trace support
	--test			Run some builtin tests

	--ast			Dump the AST, don't generate a program
	--tree			Dump the parsed s-expression tree (without transforms)




== The language

The language is made of the common features that I could identify among programming languages.  So it does not support objects, first class functions, closures, inheritence, or other popular language features.  In general, you can define functions and call them, and define data structures and access them.

The payoff to this limition is that you can convert your code into 4 different languages, and there are more on the way.

== The AST

The AST is a direct reflection of the quon code.  Additional data for compilation is stored in "tags".  Tags are hash tables (right now, association lists) that are "attached" to boxes.  At the moment, this only works for boxes.  So an AST node would just be a symbol, with the followng tags attached

        ("line"    -1)              Line number of source file, deprecated
        ("file"    base)            File name of source file, deprecated
        ("name"    "node type")     e.g. statement, expression
        ("subname" "subtype")       node subtype, e.g. setter, getter


Specialised nodes often have more keys.  



Types

Types are currently not checked at all.  Quon simply believes you when you use a type, and if it is wrong, you will get an error from the target language.  Type checking and inference is planned.

However, types are passed through to the target language.  You can specify a native type and quon will generate code that uses it.  This is how quon interfaces with native code.

Structs

Structs are fully supported.  You can define structs made of structs, and access and set members.

Native code generation.  

Native code generators are provided in the q/ directory, with a file name related to the language target.  e.g. java.qon, node.qon, ansi.qon .  These files contain the code needed to walk the AST and generate code for the target system.  As part of this, each generator tends to include a preamble that sets up some global variables and parses the command line into them.  This is kept to a minimum because it is very diffcult to maintain and understand.  Where possible, target-specific code is kept in the q/shim directory.  These files are still in qon format, but the output is usually only valid for the target platform.  Examples of this are the math functions, binary operators, and functions to access structures (get-struct, set-struct).

Shims are the only code that is optionally compiled into quon.  All the other code is always included in the compile, resulting in a compiler that can output multiple languages based on the command line switch.  However the shim files define the same function names with different implementations, so they can't all be compiled in at the same time.


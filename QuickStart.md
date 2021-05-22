# Quick Start

Quon is a compiler that compiles programs to other languages - it is a _transpiler_.  It can also compile itself to other languages, so it exists in many forms.  This guide assumes that you are using a compiled binary version, but the same instructions work for interpreted languages, you just have to adapt the command line to run the interpreter.

## Tests

Quon has many built-in tests that I use during development.  Run them with

    quon --test

## Compiling a program

    quon source.qon --ansi3 > source.c

You can choose the output language on the command line.  The default is ANSI C, but the following command lines are supported:

* --perl

Output perl code

* --ast

Output the complete abstract syntax tree, in s-expression form.

* --tree

Output the parsed program, in s-expression form.

* --ansi

The old C generator

* --ansi2

The less old C generator

* --ansi3

The new C generator

* --java

Outputs a single java class containing the program.

### Compiler settings

When you compile the C code, you should switch optimisations on.  For GCC, this means using the -O3 flag

    gcc -O3 source.c

Quon uses a lot of recursion, and -O3 switches on tail calls to prevent running out of stack space.

If you continue running out of stack space, look in the build scripts to see which options work for your platform.

## Hello world

    ((includes base.qon)
     (types)

     (functions

      (int start () (declare)
           (body
            (printf "%s" "Hello world\n")
            (return 0)))

    ))

There are few things to note here:

* All programs must have a "start" routine that returns a success code, which will be used as the status of your program when it finishes.  The start routine is the "main" routine, it is called when your program starts.
* This is a typed language.  You can use any types from the target language without declaring them first.  Quon provides some portable types:  int, float, string and box.
* Printf calls the native printf.  Bizarrely, printf is the most consistently ported function across all languages.
* You can call any functions from your target language without having to declare them first.  Quon has 100% integration with the target language.  You can call any function from the target language, and the target language can  call any function in quon.  Naturally, if you do this, your program becomes unportable.
* This is not LISP or SCHEME.  It looks like it, due to the syntax, but is actually a simple compiled language much closer to C and Pascal than LISP or any p-lang.

## Debugging:  trace and stepTrace

Running your program with ```--trace``` prints a message every time the program enters or leaves a function.  This option is always compiled in, unless you compile with ```--release```.  You can also activate it within your program by calling ```[tron]```, and switch it off with ```[troff]```

Running your program with ```--stepTrace``` prints a message for every line in your program.  This creates an amazing amount of output, so you usually need to prepare a special, smaller, version of your input data.  You activate it within your program by calling ```[stron]``` in your code, and turn it off with ```[stroff]```.

## Learning more

The examples directory contains simple programs that test the compiler.

## Modifying the compiler

The compiler is actually very simple, and open source.  Adding new features is easy, and adding new target languages is even easier.  If you do add something new, send a pull request so everyone can enjoy your new feature!

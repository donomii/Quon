# Quon

Quon is a self hosting programming language.  A self-compiling compiler, or a kind of portable macro language.  It is a system that can compile itself into many other programming languages, and then compile itself again from there.  It can run on any system that it has a compiler target for, and adding new targets is relatively easy.

## Write your program in every language

Quon is a self-hosting compiler that targets other languages, rather than direct machine code.  It uses the data types and functions of the host language, and is completely interoperable with it.  This provides access to all the libraries and abilities of the host language, (but then the program is no longer portable).

## Build portable libraries

Despite the focus on portable programs, the real use of Quon is building portable libraries.  Write your program as a library, and you can be confident that no matter which language you end up using, your library will be available there.

## Current status

The C, Java, and Perl backends work completely.  The Node.js backend produces code that works, but it is failing some tests.

## Compiling

Run bootstrap.bash, or bootstrap.bat on windows.  This will use the platform C compiler to compile the C implementation of Quon.  If you don't have a C compiler installed, you can try the Perl, Java, or Node.js versions in the bootstrap/ directory.  Quon definitely works with GCC on windows and Clang on MacOSX, other compilers _should_ work.

Then run build.bash, or buildwin.bat.  This will create files for all the possible backends and put them in build/

Then check out the longer [Guide](QuickStart.md)/

## Compile to multiple languages

Quon transpiles to C, perl, Javascript (nodejs) and Java.  You can choose the output language with a command line switch:

    ./quon hello.qon --node > test.js
    node --stack_size=9999999999 test.js


    ./quon hello.qon --perl > test.pl
    perl test.pl

    ./quon hello.qon --java > test.java
	mkdir quon
	javac -d ./ test.java
	java -Xss100M -cp . quon/MyProgram --test
	jar -cvfm hello.jar MANIFEST.MF quon/*.class
	java -Xss100M -jar hello.jar


    ./quon hello.qon > test.c
    gcc test.c
    ./a.out

See build.bat and build.bash for more detailed examples

## Known bugs

### Unicode

Quon does not support unicode.  I rely on the underlying programming language for string support, so if that language does not have unicode support, then Quon can't have it either.  Worse, Quon cannot detect unicode support, so instead it silently corrupts the string and gets confused.  If your compile starts failing and the code looks ok, check for unicode characters.

### Garbage collection

There is currently no built-in garbage collector, so any program compiled to C will run out of memory if it runs for long enough.  The other target languages have garbage collectors, so memory will be reclaimed as usual.


## Demo

```
	mandelbrot.exe
```

```
                      ................::::::::::::::::::::::::::::::::::::::::::!!!!!!!!!!!//>o#*$o/////!!!!!!!!!::::::::::.................................
                     ...............:::::::::::::::::::::::::::::::::::::::::!!!!!!!!!!!!////>>+&*+>>>>///!!!!!!!!!::::::::::...............................
                    .............:::::::::::::::::::::::::::::::::::::::::!!!!!!!!!!!!!!/////>>o$#&++ooo*o/!!!!!!!!!!!::::::::::............................
                   ............::::::::::::::::::::::::::::::::::::::::!!!!!!!!!!!!!!!//////>>oo*%@#*%@O$+>//!!!!!!!!!!!::::::::::..........................
                  ..........:::::::::::::::::::::::::::::::::::::::::!!!!!!!!!!!!!!!!///////>oo++*&0#@&*+o>>//!!!!!!!!!!!::::::::::::.......................
                 .........::::::::::::::::::::::::::::::::::::::::!!!!!!!!!!!!!!!!!///////>>oo++*%$##$%*+oo>////!!!!!!!!!!!::::::::::::.....................
                .........:::::::::::::::::::::::::::::::::::::::!!!!!!!!!!!!!!!!!!///////>>o+%*%$#####@%++o>>/////!!!!!!!!!!::::::::::::....................
               ........:::::::::::::::::::::::::::::::::::::::!!!!!!!!!!!!!!!!!!///////>>o*&@#00######@$&#@+>>///////!!!!!!!!!::::::::::::..................
              .......:::::::::::::::::::::::::::::::::::::::!!!!!!!!!!!!!!!!!!/////>>>>>o+*&$##############&o>>////////!!!!!!!!:::::::::::::................
              ......::::::::::::::::::::::::::::::::::::::!!!!!!!!!!!!!!!!!/////>>>>>>ooo++%0############@&*oo>>>/////////!!!!!!:::::::::::::...............
             .....::::::::::::::::::::::::::::::::::::::!!!!!!!!!!!!!!!!////>>>>>>>>oooo++*&##############$*+ooo>>>>>///////!!!!!::::::::::::::.............
            .....:::::::::::::::::::::::::::::::::::::!!!!!!!!!!!!!!!/////>ooooooooooo++**%&$############0&%*+++oo>>>>>>>>>>//!!!!::::::::::::::............
           .....::::::::::::::::::::::::::::::::::::!!!!!!!!!!!!!!/////>>+#$%#$#%*+**$$#&&$$O@###########O$$&%%&#*+ooooooo+O0>/!!!!::::::::::::::...........
           ....:::::::::::::::::::::::::::::::::::!!!!!!!!!!!/////////>>oo*$###0O#&%&########################@@###**+++++*O#*o>//!!!::::::::::::::..........
          ....:::::::::::::::::::::::::::::::::!!!!!!!!!!///////////>>>>oo##@######0#############################@$%%&##O&O#OO%///!!!::::::::::::::.........
          ...::::::::::::::::::::::::::::::::!!!!!!!!/////////////>>>>>oo+*%########################################0########%o>//!!!:::::::::::::::........
         ...::::::::::::::::::::::::::::::!!!!!!////////////////>>>>>>oo++*%O##############################################$%+>>///!!!:::::::::::::::.......
         ..::::::::::::::::::::::::::::!!!!!//////////////////>>>>>>>o++%&&&0###############################################+o>>///!!!!:::::::::::::::......
        ..::::::::::::::::::::::::::!!!!!///////////////////>>>>>>>oo*###################################################0&*+oo>>///!!!!:::::::::::::::.....
        ..:::::::::::::::::::::!!!!!!!//o%o>>>>>>>>>>>>>>>>>>>>oooo++*$####################################################O*+oo>///!!!!:::::::::::::::.....
        .:::::::::::::::::!!!!!!!!!///>>o*0%+ooooooooooooooooooooo+++%&O###################################################O&**%%>//!!!!!:::::::::::::::....
       .:::::::::::::!!!!!!!!!!!!////>>>o%@&*++ooo++*##*++oooooo++++%@########################################################0#%o//!!!!!::::::::::::::::...
       .:::::::::!!!!!!!!!!!!!///////>>>o*$@$O&O&**%&##$%*%&**+****%&O###########################################################>>/!!!!!!:::::::::::::::...
       :::::::!!!!!!!!!!!!!!////////>>>oo+*%$#####O$O@###O##&%***%%%O########################################################O%+o>>/!!!!!!::::::::::::::::..
      .:::::!!!!!!!!!!!!!!!/////////>>ooo+**&O################@$&&&$0########################################################O%*o>//!!!!!!::::::::::::::::..
      .:::!!!!!!!!!!!!!!!//////////>>oooo**%$@##################0OO0###########################################################Oo>//!!!!!!!:::::::::::::::..
      :::!!!!!!!!!!!!!!///////////>oooo+*#O0######################@##########################################################@&+>>//!!!!!!!::::::::::::::::.
      :!!!!!!!!!!!!!!!////////>>>oO*+***%&O##################################################################################@%o>///!!!!!!!::::::::::::::::.
      :!!!!!!!!!!!!!///>>>>>>>ooo+&#$&&$$O##################################################################################O%o>>///!!!!!!!::::::::::::::::.
      !!!!!!!!!!!//>>>>>>>>ooooo+*%&#######################################################################################@&o>>////!!!!!!!::::::::::::::::.
      /////>>>>o+*ooooo>>o+++++%%%#0#######################################################################################*+o>>////!!!!!!!!:::::::::::::::.
      >>/ooo>++*O#&**+%&$%&%%$$#0@######################################################################################0&*+oo>>////!!!!!!!!:::::::::::::::.
      ///oo>>o++&#&**+*%$%***%&#O0#######################################################################################&*+oo>>////!!!!!!!!:::::::::::::::.
      !////>>>>o++oooo>>>ooooo+***$O#######################################################################################*+o>>////!!!!!!!!:::::::::::::::.
      !!!!!!!!!!!!/>>>>>>>>>oooo+*%&#@@######################################################################################+o>////!!!!!!!::::::::::::::::.
      :!!!!!!!!!!!!!///>>>>>>>ooo+$#&%%&&$##################################################################################@0+>>///!!!!!!!::::::::::::::::.
      ::!!!!!!!!!!!!!!/////////>>o*+++**%&0##################################################################################O*o>///!!!!!!!::::::::::::::::.
      :::!!!!!!!!!!!!!!///////////>oooo+*#$O@#####################@############################################################*o>//!!!!!!!::::::::::::::::.
      .:::!!!!!!!!!!!!!!!//////////>>oooo+*%$###################0OOO############################################################o>//!!!!!!!:::::::::::::::..
      .:::::!!!!!!!!!!!!!!!/////////>>ooo+**&O#################&&&&$0########################################################O%+o>//!!!!!!::::::::::::::::..
       :::::::!!!!!!!!!!!!!!!////////>>oo+*%$#####$&O0###O##&%****%%$########################################################@%+o>>/!!!!!!::::::::::::::::..
       .:::::::::!!!!!!!!!!!!!!//////>>>o*O0&&%O%***&#0&%***+++++**%&@##########################################################&>>/!!!!!!:::::::::::::::...
       .:::::::::::::!!!!!!!!!!!!/////>>o*#&+++oooo++%#*++oooooo++++*$########################################################O#*o//!!!!!::::::::::::::::...
        .:::::::::::::::::!!!!!!!!!///>>o*#%+ooooooooooooooooooooo+++*&O###################################################O%**%*>//!!!!!:::::::::::::::....
        ..::::::::::::::::::::::!!!!!!//ooo>>>>>>>>/////>>>>>>>>oooo+*####################################################@$++oo>///!!!!:::::::::::::::.....
        ..::::::::::::::::::::::::::!!!!!///////////////////>>>>>>>oo+#@##@@#############################################0&*+oo>>///!!!::::::::::::::::.....
         ..:::::::::::::::::::::::::::::!!!!!//////////////////>>>>>>o++*%%&O###############################################+o>>///!!!!:::::::::::::::......
         ...:::::::::::::::::::::::::::::::!!!!!!////////////////>>>>>oo++*%0##############################################$%+>>///!!!:::::::::::::::.......
          ...::::::::::::::::::::::::::::::::!!!!!!!!/////////////>>>>>oo+*%#######################################@O########%o>//!!!:::::::::::::::........
          ....::::::::::::::::::::::::::::::::::!!!!!!!!!!//////////>>>>oo0########O@############################@$%%&##$&$#$%*///!!!::::::::::::::.........
           ....:::::::::::::::::::::::::::::::::::!!!!!!!!!!!!////////>>oo*O###0$&%%&########################0O###*++++++*&#*o>//!!!::::::::::::::..........
            ....::::::::::::::::::::::::::::::::::::!!!!!!!!!!!!!!//////>o&$*%&#%+++*%&#&%&$O@###########O$&%**%#+oooooooo+#$>/!!!!::::::::::::::...........
            .....:::::::::::::::::::::::::::::::::::::!!!!!!!!!!!!!!!!////>>ooooooooooo+**%&$############@%*+++oo>>>>>>>>>>///!!!!::::::::::::::............
             ......:::::::::::::::::::::::::::::::::::::!!!!!!!!!!!!!!!!!////>>>>>>>oooo++*$##############$*+ooo>>>>////////!!!!!:::::::::::::..............
              ......::::::::::::::::::::::::::::::::::::::!!!!!!!!!!!!!!!!!!////>>>>>>>oo++%$#############&*oo>>>/////////!!!!!!:::::::::::::...............
              ........::::::::::::::::::::::::::::::::::::::!!!!!!!!!!!!!!!!!!//////>>>>oo*$O##############*o>>////////!!!!!!!!::::::::::::.................
               ........:::::::::::::::::::::::::::::::::::::::!!!!!!!!!!!!!!!!!!///////>>>+%$#OO######0&&$O+>>//////!!!!!!!!!!::::::::::::..................
                .........:::::::::::::::::::::::::::::::::::::::!!!!!!!!!!!!!!!!!!///////>>o+**%O######%++o>>/////!!!!!!!!!!::::::::::::....................
                 ..........::::::::::::::::::::::::::::::::::::::::!!!!!!!!!!!!!!!!!///////>ooo++%&##$%*+o>>////!!!!!!!!!!!:::::::::::......................
                  ...........::::::::::::::::::::::::::::::::::::::::!!!!!!!!!!!!!!!!///////>oo++*&#@#O%+o>>//!!!!!!!!!!!:::::::::::........................
                   ............::::::::::::::::::::::::::::::::::::::::!!!!!!!!!!!!!!!//////>>>o*%@0**&&##>//!!!!!!!!!!:::::::::::..........................
                    .............:::::::::::::::::::::::::::::::::::::::::!!!!!!!!!!!!!!/////>>o&#%+oooo+>/!!!!!!!!!!:::::::::::............................
                     ...............:::::::::::::::::::::::::::::::::::::::::!!!!!!!!!!!!////>>+$*o>>>>///!!!!!!!!!::::::::::...............................
```


## Language specification

The compiler is its own specification.  The compiler is in the compiler.qon file, and the q/ directory, and is written in s-expressions.  These are read into an AST, and then compiled into a target language.

NOTE!  Quon is not Lisp or Scheme.  It just uses s-expressions for convenience.

Quon is not really a full programming language.  It is a compiler that compiles (transpiles!) an AST into many other languages.  It adds features that the target language doesn't have, but ultimately all functionality is provided by the target language.  This means that it is only possible to write trivial programs that are cross-platform.

However, it is easy to write _libraries_ that are cross platform.  Using quon, you can write sort routines, mathematical functions and anything else that manipulates data, and then compile it for many different target platforms.

Quon offers _perfect_ integration with the target language.  You can call any function in your target language from quon, and you can call any quon function from your target language.

## Types and variables

Quon uses types from the target language.  If you use a type that isn't declared in your program, quon will assume that it will be provided in the target language.

In order to stop you going insane trying to manage basic types between different platforms, quon provides the following types, which will be translated into their closest equivalent in the target language:

* int
* float
* string
* byteArray
* bool

Don't rely on these being the same format, or the same size, across platforms!  For instance, if there is no native Boolean type, quon will usually just use an integer, and then true/false will just be 1/0

There is no character type.  If you want a character, use a string with one character in it.

## Complete language description

Read the entire  [quon AST language](Language.md)

## Built-in functions

Quon currently provides these functions and statements

### clone

### newVoid

### car, cdr, cons, isList, isEmpty, listLength, displayList

### nop

### boxString, boxSymbol, boxBool, boxInt unBoxString, unboxInt, etc

Convert to and from native data types.  See the entry on Boxes for more details.

### assertType type box

panic if the box contains the wrong type

### stringify

Create a string representation of a box value, regardless of its underlying type

### hasTag, getTag, setTag, getTagFail

See the section on tags

## Tags

Tags are notes that you can place on data.  At the moment, only boxes can be tagged, but I hope that I will be able to tag everything, eventually.

Tags are key/value data that can be attached to a box.  Quon uses tags heavily during parsing, to store things like line number, type, file origin, etc.

Tags solve a common problem in programming, which is that the programmer needs to annotate some data without actually altering that data.  The parse tree is the most clear example.  You have a complex data structure, like a program, and you want to add extra data to the structure for debugging, such as line number and source file.  Normally you can't modify the data structure, because you don't "own" the data type.  If you change the data type, you can no longer pass it to any of the old functions, because they only accept the old type, not your new, improved type.

Some languages solve this by having generics, or inheritence but quon doesn't have generics yet, and generics don't work exactly like tags.  So instead quon hides the extra data.  Now the old functions can keep working like usual, but you can also keep extra data in your data structure that the old functions can't see.

## Boxes

Boxes are data structures that can wrap any other type.  They are a "any" type, or a "varying" type.  Most compile-time type systems allow you to create a list of strings, or a list of integers, but not combine the two in list of strings and integers.  But if you wrap your strings and integers in boxes, then you can mix and match them however you like.

Boxes solve a problem of static type systems, by wrapping data and turning it into an "any" type.

While compile-time type systems have many benefits, they have a massive drawback as well:  dealing with flexible data structures.  Compile-time typed languages have immense difficulty dealing with JSON and the (moderately) complicated data structures that you tend to find being passed around in JSON.

If you don't know  what the JSON structure will be ahead of time, then you have to dedicate thousands of lines of code, or complex libraries, to dealing with it.  Quon uses a little bit of both, with boxes.

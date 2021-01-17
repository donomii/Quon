#!/bin/bash
./quon compiler.qon   > working/quon.c
gcc -O2 -flto   working/quon.c -Wl,-stack_size,4000000 -o build/quon_new
build/quon_new --test
build/quon_new compiler.qon



mkdir working
build/quon_new compiler.qon --java > working/test.java
cd working
mkdir quonverter
java -Xss100M -cp . quonverter/MyProgram --test
javac -d quonverter test.java
jar -cvfm MyProgram.jar MANIFEST.MF quonverter/*.class
java -Xss100M -jar MyProgram.jar --test
cd ..


#./quon_new examples/mandelbrot.qon --java > test.java
#rm -r quonverter
#mkdir quonverter
#javac -d ./ test.java
#java -Xss100M -cp . quonverter/MyProgram --test
#jar -cvfm mandelbrot.jar MANIFEST.MF quonverter/*.class
#java -Xss100M -jar mandelbrot.jar --test

./quon_new compiler.qon --lua > test.lua
lua test.lua  compiler.qon --ast

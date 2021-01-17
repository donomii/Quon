#!/bin/bash
rm -r release

gcc -O3   bootstrap/quon.c -o quon
./quon --test
mkdir release
cp quon release/


./quon examples/mandelbrot.qon  > mandelbrot.c 
gcc -O3   mandelbrot.c -o release/mandelbrot


./quon compiler.qon --java > test.java
mkdir quonverter
javac -d ./ test.java
jar -cvfm MyProgram.jar MANIFEST.MF quonverter/*.class
java -Xss100M -jar MyProgram.jar --test
mv MyProgram.jar release/quon.jar


./quon_new examples/mandelbrot.qon --java > test.java
rm -r quonverter
mkdir quonverter
javac -d ./ test.java
jar -cvfm mandelbrot.jar MANIFEST.MF quonverter/*.class
java -Xss100M -jar mandelbrot.jar
mv mandelbrot.jar release/

rm -r quonverter


./quon compiler.qon --perl > quon.pl
mv quon.pl release/
./quon examples/mandelbrot.qon --perl > release/mandelbrot.pl

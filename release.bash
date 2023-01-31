#!/bin/bash
rm -r release
mkdir release

gcc -O3 -Wno-parentheses-equality  bootstrap/quon.c -o release/quon
./release/quon --test


./release/quon examples/mandelbrot.qon  > mandelbrot.c 
gcc -O3 -Wno-parentheses-equality  mandelbrot.c -o release/mandelbrot


./release/quon compiler.qon --java > test.java
mkdir quonverter
javac -d ./ test.java
jar -cvfm MyProgram.jar MANIFEST.MF quonverter/*.class
java -Xss100M -jar MyProgram.jar --test
mv MyProgram.jar release/quon.jar
rm -r quonverter


./release/quon examples/mandelbrot.qon --java > test.java
mkdir quonverter
javac -d ./ test.java
jar -cvfm mandelbrot.jar MANIFEST.MF quonverter/*.class
java -Xss100M -jar mandelbrot.jar
mv mandelbrot.jar release/

rm -r quonverter


./release/quon compiler.qon --perl > release/quon.pl
./release/quon examples/mandelbrot.qon --perl > release/mandelbrot.pl

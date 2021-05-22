rm -rf release
mkdir release
gcc -O3  -Wl,--stack,167108864 bootstrap\quon.c -o working\quon.exe
working\quon.exe compiler.qon --ansi3 --release > working\quon_release.c
rm release\quon.exe
gcc -O3  -Wl,--stack,167108864  working\quon_release.c -o release\quon.exe
strip release\quon.exe
cp -r q release/
cp compiler.qon release/

release\quon examples/mandelbrot.qon --release > working\mandelbrot.c 
gcc -O3   working\mandelbrot.c -o release\mandelbrot


quon release\compiler.qon --perl --release > release\quon.pl
quon examples/mandelbrot.qon --perl --release > release/mandelbrot.pl


quon compiler.qon --node  --release > release/quon.js
quon examples/mandelbrot.qon --node --release > release/mandelbrot.js

quon compiler.qon --java > working\quon.java
cd working
rm -r quonverter
mkdir quonverter
javac -d ./ quon.java
jar -cvfm MyProgram.jar MANIFEST.MF quonverter/*.class
java -Xss100M -jar MyProgram.jar --test
mv MyProgram.jar ../release/quon.jar
cd ..


quon_new examples/mandelbrot.qon --java > test.java
rm -r quonverter
mkdir quonverter
javac -d ./ test.java
jar -cvfm mandelbrot.jar MANIFEST.MF quonverter/*.class
java -Xss100M -jar mandelbrot.jar
mv mandelbrot.jar release/




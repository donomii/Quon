mkdir work
mkdir work\quonverter
quon.exe compiler.qon   > work\quon.c
gcc -O3 -Wl,--stack=999999999 work\quon.c -o quon_new
quon_new.exe --test
quon_new compiler.qon --perl  > work\test.pl
perl test.pl --test
quon_new compiler.qon --node  > work\test.js
node --stack-size=6000 test.js --test
mkdir quonverter
quon_new compiler.qon --java  > work\quonverter\test.java
cd work
cd quonverter
javac test.java
cd ..
cd ..
jar cvfm quonverter.jar MANIFEST.MF work\quonverter\*.class
java -Xmx1024M -Xss64M -jar quonverter.jar --test


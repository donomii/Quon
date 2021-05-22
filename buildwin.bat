working\quon compiler.qon --ansi3 > working\quon.c
rm working\quon_new.exe
gcc -O3  -Wl,--stack,167108864  quon.c -o working\quon_new
working\quon_new --test
working\quon_new compiler.qon --perl > working\quon.pl
perl working\quon.pl --test
working\quon_new compiler.qon --node > working\quon.js
node working\quon.js --test

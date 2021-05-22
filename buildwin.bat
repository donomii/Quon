mkdir working
quon compiler.qon --ansi3 --release > quon.c
rm quon_new.exe
gcc -O3  -Wl,--stack,167108864  quon.c -o quon_new -g
quon_new --test
quon_new compiler.qon --perl > working\quon.pl
perl working\quon.pl --test
quon_new compiler.qon --node > working\quon.js
node working\quon.js --test

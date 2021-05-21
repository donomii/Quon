quon compiler.qon --ansi3 > quon.c
rm quon_new.exe
gcc -O3  -Wl,--stack,167108864  quon.c -o quon_new -g
quon_new --test
quon_new compiler.qon --perl > test.pl
perl test.pl --test

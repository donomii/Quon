quon compiler.qon   > quon.c
gcc -O3  -Wl,--stack,167108864  quon.c -o quon_new -g
quon_new --test
REM quon_new compiler.qon
quon_new compiler.qon --perl > test.pl
perl test.pl --test

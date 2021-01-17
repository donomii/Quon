cp quon.exe quon1.exe
echo Preparing quon2.c
quon1.exe compiler.qon   > quon1.c
rm quon2.exe
echo Compiling quon2.c into quon2
gcc -O3 -Wl,--stack=999999999 quon1.c -o quon2.exe -Wno-unknown-escape-sequence
echo Testing quon2
quon2 --test
echo Preparing quon1.c using quon2
quon2 compiler.qon > quon2.c
#echo Comparing quon1.c and quon2.c
#diff quon1.c quon2.c
echo Removing quon1
rm quon1
echo Compiling quon1.c into quon1
gcc -O3 -Wl,--stack=999999999 quon2.c -o quon1.exe -Wno-unknown-escape-sequence

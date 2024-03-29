#!/bin/bash
rm working/quon1
ln working/quon working/quon1
rm working/quon1.exe
cp working/quon.exe working/quon1.exe
echo Preparing quon1.c
./working/quon1 compiler.qon    > working/quon1.c
#./working/quon1 compiler.qon --node  > working/quon1.js
rm working/quon2
rm working/quon2.exe
echo Compiling quon1.c into quon2
gcc -O3 -Wl,-stack_size,4000000 -Wno-format-security working/quon1.c -o working/quon2 -Wno-unknown-escape-sequence -Wno-parentheses-equality
echo Testing quon2
./working/quon2 --test
#node ./working/quon2.js --test
#./working/quon_new compiler.qon
echo Preparing quon1.c using quon2
./working/quon2 compiler.qon > working/quon2.c
#node ./working/quon2 compiler.qon --node > working/quon2.js
#echo Comparing quon1.c and quon2.c
#diff quon1.c quon2.c


echo Removing quon1
rm working/quon1
rm working/quon1.exe
echo Compiling quon1.c into quon1
gcc -O3 -Wl,-stack_size,4000000 -Wno-format-security working/quon2.c -o working/quon1 -Wno-unknown-escape-sequence -Wno-parentheses-equality
echo Testing quon1
./working/quon1 --test
#node ./working/quon1.js --test
#bash circular.bash

echo working/quon1 updated to latest version

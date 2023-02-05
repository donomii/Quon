#!/bin/bash
mkdir build
gcc -O3 -Wl,-stack_size,4000000 -Wno-parentheses-equality bootstrap/quon.c -o build/quon
echo Built build/quon
gcc -O3 -Wl,-stack_size,4000000 -Wno-parentheses-equality bootstrap/quon.c -o build/quon_new
echo Built build/quon_new


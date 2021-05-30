#!/bin/bash
mkdir build
gcc -O3 -Wl,-stack_size,4000000 bootstrap/quon.c -o build/quon

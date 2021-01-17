#!/bin/bash
./quon astwalk.qon   > astwalk.c
gcc -O3   astwalk.c -Wl,-stack_size,4000000 -o astwalk
./astwalk


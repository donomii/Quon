mkdir working
gcc -O3 -Wl,--stack=999999999 bootstrap\quon.c -o working\quon.exe

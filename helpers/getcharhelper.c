#include <stdio.h>
#include <termios.h>
#include <unistd.h>

int getCHAR( ) {
    struct termios oldt,
                 newt;
    int            ch;
    tcgetattr( STDIN_FILENO, &oldt );
    newt = oldt;
    newt.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newt );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
    return ch;
}
int main() {
  setbuf(stdout, NULL);
    int c = getCHAR();
    int nl = 10;
    
    while (1) {
        putchar(c);
        putchar(nl);
        c = getCHAR();
    }
}

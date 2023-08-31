#include "Draw.hpp"
#include <curses.h>

int main(int argc, char *argv[]){
    vpoint p = input();
    draw(p);
    p.clear();
    return 0;
}

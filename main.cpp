#include "src/headers.h"
#include "src/Tscreen.cpp"

class Tscreen;

int main(){
    Tscreen screen;
    //screen.clear();
    screen.plot(32,32,0,0,1);
    screen.print();
    return 0;
}

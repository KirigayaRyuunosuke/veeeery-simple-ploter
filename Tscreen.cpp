#include "headers.h"

class Tscreen{

class Tpixel{
private:
    class Tchar{
    public:
            int red{5}, green{5}, blue{5}; //values 0-5
            char charracter{' '};
            void setColor(int r,int g, int b){
            red = r; green = g; blue = b;
        }
            void setChar(char newChar){
                charracter = newChar;
            }
    };
    class Tbg{
    public:
        int red{3}, green{0}, blue{5}; //values 0-5
        void setColor(int r,int g, int b){
            red = r; green = g; blue = b;
        }
    };

    //code = 16 + (red * 36) + (green * 6) + blue
public:
    Tbg BG;
    Tchar FG;
    void print(){
        std::cout << "\033[" << 48 << ";" << 5 << ";"
        << 16 + (BG.red * 36) + (BG.green * 6) + BG.blue << ";"
        << 38 << ";" << 5 << ";"
        << 16 + (FG.red * 36) + (FG.green * 6) + FG.blue
        << "m"
        << FG.charracter
        << "\033[m";
    }
};

    constexpr static int x{64};
    constexpr static int y = x / 2;

    Tpixel pixels[y][x];


public:
    int size = x;

    void print(){
        for(int j{0}; j < y; j++){
            for(int i{0}; i < x; i++){
                pixels[y-1-j][i].print();
            }
            std::cout << '\n';
        }
    }
    void clear(){
        for(int j{0}; j < y; j++){
            for(int i{0}; i < x; i++){
                pixels[j][i].BG.setColor(5, 5, 5);
                pixels[j][i].FG.setChar(' ');
            }
        }
    }
    void axis(int offset){
        for(int j{0}; j < y; j++){
            pixels[j][offset].FG.setChar('|');
        }
        for(int i{0}; i < x; i++){
            pixels[offset/2][i].FG.setChar('-');
        }
        pixels[offset/2][offset].FG.setChar('+');
    }
    void axis(int offsetX, int offsetY){
        for(int j{0}; j < y; j++){
            pixels[j][offsetX].FG.setChar('|');
        }
        for(int i{0}; i < x; i++){
            pixels[offsetY/2][i].FG.setChar('-');
        }
        pixels[offsetY/2][offsetX].FG.setChar('+');
    }

    void plot(int offsetX,int offsetY,int a,int b = 0,int c = 0,int d = 0){
        axis(offsetX, offsetY);
        int j{};
        for(int i{0}; i < x; i++){
            //((i-offset)/2+offset/2)
            // int func = a*i+b*i*i;
            if((i-offsetX) > 0){
                j = (i-offsetX)/2;
            }
            else{
                j = (i-offsetX-1)/2;
            }
            j = a * j + b * j * j + c * j * j * j + d * j * j * j * j;
            j+=offsetY/2;
            if(!(j > y || j < 0))
                pixels[j][i].FG.setChar('a');
        }
    }
    // void plot(int offset,int a,int b = 0,int c = 0,int d = 0){
    //     axis(offset);
    //     int j{};
    //     for(int i{0}; i < x; i++){
    //         //((i-offset)/2+offset/2)
    //         // int func = a*i+b*i*i;
    //         if((i-offset) > 0){
    //             j = (i-offset)/2;
    //         }
    //         else{
    //             j = (i-offset-1)/2;
    //         }
    //         j = a * j + b * j * j + c * j * j * j + d * j * j * j * j;
    //         j+=offset/2;
    //         if(!(j > y || j < 0))
    //             pixels[j][i].FG.setChar('a');
    //     }
    // }
};

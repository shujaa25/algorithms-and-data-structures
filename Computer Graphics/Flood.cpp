#include<iostream>
#include<graphics.h>

using namespace std;

void flood_fill(int x, int y, int old_color, int new_color){
    if(getpixel(x, y) == old_color){
        putpixel(x, y, new_color);
        flood_fill(x+1, y, old_color, new_color);
        flood_fill(x-1, y, old_color, new_color);
        flood_fill(x, y+1, old_color, new_color);
        flood_fill(x, y-1, old_color, new_color);
        flood_fill(x+1, y+1, old_color, new_color);
        flood_fill(x+1, y-1, old_color, new_color);
        flood_fill(x-1, y+1, old_color, new_color);
        flood_fill(x-1, y-1, old_color, new_color);
    }
}

int main(){
    int gd = DETECT, gm;
    char c = ' ';

    initgraph(&gd, &gm, &c);

    rectangle(100,100,300,300);
    flood_fill(101,101,BLACK, YELLOW);

    getch();
    closegraph();
    return 0;
}

#include<iostream>
#include<graphics.h>

using namespace std;

void plot(int x, int y, int x_c, int y_c){
    putpixel(x+x_c, y+y_c, RED);
}

int main(){
    int gd = DETECT, gm;
    char c = ' ';

    int r, x_c, y_c;
    cout << "[BRESENHAM's CIRCLE ALGO]" << endl;
    cout << "Enter radius: ";
    cin >> r;
    cout << "Enter center points (x, y): ";
    cin >> x_c >> y_c;

    initgraph(&gd, &gm, &c);

    int p = 3-2*r, x = 0, y = r;

    do{
        plot(x, y, x_c, y_c);
        plot(x, -y, x_c, y_c);
        plot(-x, y, x_c, y_c);
        plot(-x, -y, x_c, y_c);
        plot(y, x, x_c, y_c);
        plot(y, -x, x_c, y_c);
        plot(-y, x, x_c, y_c);
        plot(-y, -x, x_c, y_c);
        if(p < 0){
            x += 1;
            p += 4*x +6;
        }else{
            x += 1;
            y -= 1;
            p += 4*(x-y) +10;
        }
    }while(x < y);

    getch();
    closegraph();
    return 0;
}

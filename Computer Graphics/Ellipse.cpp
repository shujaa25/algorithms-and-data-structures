#include<iostream>
#include<graphics.h>

using namespace std;

void plot(int x, int y, int x_c, int y_c){
    putpixel(x+x_c, y+y_c, YELLOW);
}

int main(){
    int gd = DETECT, gm;
    char c = ' ';

    int rx, ry, x_c, y_c;
    cout << "[ELLIPSE ALGO]" << endl;
    cout << "Enter rx and ry: ";
    cin >> rx >> ry;
    cout << "Enter center points (x, y): ";
    cin >> x_c >> y_c;

    initgraph(&gd, &gm, &c);

    int x = 0, y = ry;
    int p1 = (ry*ry)+(rx*rx)/y-ry*(rx*rx);
    //int p1 = (ry*ry)+(rx*rx)*ry+(rx*rx)/4;
    int dx = 2*(ry*ry)*x;
    int dy = 2*(rx*rx)*y;

    do{
        plot(x, y, x_c, y_c);
        plot(-x, y, x_c, y_c);
        plot(x, -y, x_c, y_c);
        plot(-x, -y, x_c, y_c);
        if(p1 < 0){
            x++;
            dx=dx+2*(ry*ry);
            p1=p1+dx+(ry*ry);
        }else{
            x++;
            y--;
            dx=dx+2*(ry*ry);
            dy=dy-2*(rx*rx);
            p1=p1+dx-dy+(ry*ry);
        }
    }while(dx < dy);

    int p2 = (ry*ry)*((x+.5)*(x+.5))+(rx*rx)*((y-1)*(y-1))-(rx*rx)*(ry*ry);

    do{
        plot(x, y, x_c, y_c);
        plot(-x, y, x_c, y_c);
        plot(x, -y, x_c, y_c);
        plot(-x, -y, x_c, y_c);
        if(p2 > 0){
            y--;
            dy=dy-2*(rx*rx);
            p2=p2-dy+(rx*rx);
        }else{
            x++;
            y--;
            dx=dx+2*(ry*ry);
            dy=dy-2*(rx*rx);
            p2=p2+dx-dy+(rx*rx);
        }
    }while(y>=0);

    getch();
    closegraph();
    return 0;
}

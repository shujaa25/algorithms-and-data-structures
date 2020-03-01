
#include<cmath>
#include<iostream>
#include<graphics.h>

using namespace std;

void plot(int x, int y, int x_c, int y_c){
    putpixel(x+x_c, y+y_c, RED);
}

int main(){
    int gd = DETECT, gm;
    char c = ' ';

    int x1 = 300, y1 = 100;
    int x2 = 200, y2 = 200;
    int x3 = 400, y3 = 200;
    int sx, sy;

    cout << "[Scaling Algo]" << endl;
    cout << "Enter coordinates for triangle" << endl;
    cout << "x1 y1 x2 y2 x3 y3" << endl;
    cin  >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    cout << "Enter scaling factors: " << endl;
    cout << "sx sy" << endl;
    cin >> sx >> sy;

    initgraph(&gd, &gm, &c);
    //setcolor(RED);
    line(x1,y1,x2,y2);
    line(x2,y2,x3,y3);
    line(x3,y3,x1,y1);

    float tm[3][3] = {{x1,y1,1}, {x2,y2,1},{x3,y3,1}};
    float sm[3][3] = {{sx, 0, 0}, {0, sy, 0}, {0,0,1}};

    //multiplication of tm and sm
    float fm[3][3];
    float sum = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                sum += tm[i][k]*sm[k][j];
            }
            fm[i][j] = sum;
            sum = 0;
        }
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++)
            cout << fm[i][j] << ' ';
        cout << endl;
    }

    delay(2000);
    //cleardevice();
    setcolor(YELLOW);

    line(ceil(fm[0][0]),ceil(fm[0][1]),ceil(fm[1][0]),ceil(fm[1][1]));
    line(ceil(fm[1][0]),ceil(fm[1][1]), ceil(fm[2][0]),ceil(fm[2][1]));
    line(ceil(fm[2][0]),ceil(fm[2][1]),ceil(fm[0][0]),ceil(fm[0][1]));

    getch();
    closegraph();

    return 0;
}

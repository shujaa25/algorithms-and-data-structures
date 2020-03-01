#include<cmath>
#include<iostream>
#include<graphics.h>

using namespace std;

int main(){
    int gd = DETECT, gm;
    char c = ' ';

    int x1 = 300, y1 = 100;
    int x2 = 200, y2 = 200;
    int x3 = 400, y3 = 200;
    int p1 = 1, p2 = 1;
    int ang = 5;

    cout << "[ROTATION ARBITRARY]" << endl;
    cout << "Enter coordinates for triangle" << endl;
    cout << "x1 y1 x2 y2 x3 y3" << endl;
    cin  >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    cout << "Enter rotation angle: ";
    cin >> ang;
    cout << "Enter the point for rotation (r, s): ";
    cin >> p1 >> p2;

    initgraph(&gd, &gm, &c);
    setcolor(RED);
    line(x1,y1,x2,y2);
    line(x2,y2,x3,y3);
    line(x3,y3,x1,y1);

    float tm[3][3] = {{x1,y1,1}, {x2,y2,1},{x3,y3,1}};
    float otm[3][3] = {{1,0,0}, {0,1,0},{-p1,-p2,1}};
    float rm[3][3] = {{cos(ang * 3.141592653589/180), -sin(ang * 3.141592653589/180), 0}, {sin(ang * 3.141592653589/180), cos(ang * 3.141592653589/180), 0}, {0,0,1}};
    float ptm[3][3] = {{1,0,0}, {0,1,0},{-p1,-p2,1}};

    //Translation of triangle to origin
    float fm[3][3];
    float sum = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                sum += tm[i][k]*otm[k][j];
            }
            fm[i][j] = sum;
            sum = 0;
        }
    }

    //Multiplication with rotation matrix
    float fm2[3][3];
    sum = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                sum += fm[i][k]*rm[k][j];
            }
            fm2[i][j] = sum;
            sum = 0;
        }
    }

    //Translation back to the point
    float fm3[3][3];
    sum = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                sum += fm2[i][k]*ptm[k][j];
            }
            fm3[i][j] = sum;
            sum = 0;
        }
    }

    delay(2000);
    setcolor(YELLOW);

    line(ceil(fm3[0][0]),ceil(fm3[0][1]),ceil(fm3[1][0]),ceil(fm3[1][1]));
    line(ceil(fm3[1][0]),ceil(fm3[1][1]), ceil(fm3[2][0]),ceil(fm3[2][1]));
    line(ceil(fm3[2][0]),ceil(fm3[2][1]),ceil(fm3[0][0]),ceil(fm3[0][1]));

    getch();
    closegraph();

    return 0;
}

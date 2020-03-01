#include<iostream>
#include<cmath>
#include<graphics.h>

using namespace std;

void plot(int x,int y){
	putpixel(x, y, GREEN);
}

int main(){
    int gd = DETECT, gm;
    char c = ' ';

	float x1,x2,y1,y2;
	cout << "[Bresenham's LINE ALGO]" << endl;
	cout << "Enter x1 y1 x2 y2" << endl;
	cin >> x1 >> y1 >> x2 >> y2;

    initgraph(&gd, &gm, &c);

	float dx = abs(x2-x1);
	float dy = abs(y2-y1);

	float x = x1;
	float y = y1;

	float e = 2*dy - dx;

	for(int i = 0; i <= dx; i++){
		plot(x, y);
		while(e >= 0){
			y++;
			e -= 2*dx;
		}
		x++;
		e += 2*dy;
	}
    getch();
    closegraph();
	return 0;
}

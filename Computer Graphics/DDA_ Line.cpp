#include<iostream>
#include<cmath>
#include<graphics.h>

using namespace std;

void plot(int x,int y){
	putpixel(x, y, WHITE);
}


int main(){
    int gd = DETECT, gm;
    char c = ' ';

	float x1,x2,y1,y2;
	cout << "[DDA LINE ALGO]" << endl;
	cout << "Enter x1 y1 x2 y2" << endl;
	cin >> x1 >> y1 >> x2 >> y2;

    initgraph(&gd, &gm, &c);

	float dx = x2-x1;
	float dy = y2-y1;

	float len;
	if(abs(dx) >= abs(dy))
		len = abs(dx);
	else
		len = abs(dy);

	float xinc = dx/len;
	float yinc = dy/len;

	float x = x1;
	float y = y1;

	for(int i = 0; i <= len; i++){
		plot(round(x), round(y));
		x += xinc;
		y += yinc;
	}

	getch();
    closegraph();
	return 0;
}

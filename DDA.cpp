#include<graphics.h>
#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int gd=DETECT,gm;
    float x,y,x1,y1,x2,y2,dx,dy,step,xInc,yInc;
    initgraph(&gd,&gm,NULL);
    cout<<"Enter Coordinates point A and B of line:\n";
    cin>>x1>>y1>>x2>>y2;
    dx=x2-x1;
    dy=y2-y1;

    
    if(abs(dx)>abs(dy)) //Gentle slope
        step=abs(dx);
    else
        step=abs(dy);   //Steep slope

    xInc=dx/step;
    yInc=dy/step;
    x=x1;
    y=y1;
    putpixel(x,y,WHITE);

    while(step>=0){
        x+=xInc;
        y+=yInc;
        putpixel(x,y,WHITE);
        step--;
        delay(50);
    }


    delay(500);
    closegraph();
    return 0;
}
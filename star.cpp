#include<iostream>
#include<graphics.h>

using namespace std;

void drawLine(int x1,int y1,int x2,int y2)
{
    float dx=x2-x1,dy=y2-y1,xI,yI,step,x,y;
    if(abs(dx)>abs(dy))
        step=abs(dx);
    else
        step=abs(dy);
    xI=dx/step;
    yI=dy/step;
    x=x1,y=y1;
    putpixel(x,y,WHITE);
    while(step!=0){
        x+=xI;
        y+=yI;
        putpixel(x,y,WHITE);
        step--;
    }
}

int main()
{
    int gd=DETECT,gm;
    float x1,y1,x2,y2,dx,dy,s,x,y;
    initgraph(&gd,&gm,NULL);

    drawLine(100,100,200,200);
    drawLine(200,200,300,100);
    drawLine(300,100,100,100);



    cin>>gm;
    closegraph();
    return 0;
}
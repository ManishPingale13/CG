#include<graphics.h>
#include<iostream>
#include<math.h>
using namespace std;

//DDA
/*float x1,y1,x2,y2,dx,dy,x,y,step,xInc,yInc;
    initgraph(&gd,&gm,NULL);
    cout<<"points";
    cin>>x1>>y1>>x2>>y2;
    dx=x2-x1;
    dy=y2-y1;
    if(abs(dx)>abs(dy)){
        step=abs(dx);
    }else{
        step=abs(dy);
    }
    xInc=dx/step;
    yInc=dy/step;
    x=x1;
    y=y1;

    for (int i = 0; i < step; i++)
    {
        putpixel(x,y,WHITE);
        x=x+xInc;
        y=y+yInc;
        delay(50);
    } */


   //GENTLE i.e. dx>dy
   /* BRESENHAM
   cin>>x1>>y1>>x2>>y2;
    dx=x2-x1;
    dy=y2-y1;
    s=2*dy-dx;
    x=x1;
    y=y1;
    putpixel(x,y,WHITE);
    while(x<x2){
        if(s<0){
            x++;
            s+=2*dy;
        }else{
            x++;
            y++;
            s+=2*(dy-dx);
        }
        putpixel(x,y,WHITE);
        delay(50);
    }*/


void draw(int x,int y,int xc,int yc){
    putpixel(x+xc,y+yc,WHITE);
    putpixel(-x+xc,y+yc,WHITE);
    putpixel(x+xc,-y+yc,WHITE);
    putpixel(-x+xc,-y+yc,WHITE);

    putpixel(y+xc,x+yc,WHITE);
    putpixel(-y+xc,x+yc,WHITE);
    putpixel(y+xc,-x+yc,WHITE);
    putpixel(-y+xc,-x+yc,WHITE);

}

int main(){
    float x,y,p,rad,xc,yc;
    int gd=DETECT,gm;
    initgraph(&gd,&gm,NULL);
    cout<<"centers";
    cin>>xc>>yc;
    cout<<"rad";
    cin>>rad;
    p=1-rad;
    x=0;
    y=rad;
    while(x<y){
        if(p<0){
            x++;
            p+=2*x+1;
        }else{
            x++;
            y--;
            p+=2*(x-y)+1;
        }
        draw(x,y,xc,yc);
    }

    delay(5000);
    closegraph();
    return 0;
}
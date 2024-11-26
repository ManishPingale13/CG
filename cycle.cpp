#include<iostream>
#include<graphics.h>

using namespace std;


void plot(int x,int y,int xc,int yc,int rad,int col)
{
    putpixel(x+xc,y+yc,col);
    putpixel(y+xc,x+yc,col);

    putpixel(-x+xc,y+yc,col);
    putpixel(-y+xc,x+yc,col);

    putpixel(x+xc,-y+yc,col);
    putpixel(y+xc,-x+yc,col);

    putpixel(-x+xc,-y+yc,col);
    putpixel(-y+xc,-x+yc,col);

}

void drawCircle(int xc,int yc,int rad)
{
    int x=0,y=rad;
    int p=1-rad;
    while(x<y){
        if(p<0){
            x++;
            p=p+2*x+1;
        }else{
            x++;
            y--;
            p=p+2*(x-y)+1;
        }
        plot(x,y,xc,yc,rad,WHITE);
    }
}

void drawLine(int x1,int y1,int x2,int y2)
{
    float dx=x2-x1,dy=y2-y1;
    float x=x1,y=y1;

    if(abs(dx)>abs(dy)){    //gentle
        int s=2*dy-dx;
        while(x<x2){
            if(s<0){
                x++;
                s=s+2*dy;
            }else{
                x++;
                y++;
                s=s+2*(dy-dx);
            }
            putpixel(x,y,WHITE);
        }
    }else{
        int s=2*dx-dy;
        while(x<x2){
            if(s<0){
                y++;
                s=s+2*dx;
            }else{
                x++;
                y++;
                s=s+2*(dx-dy);
            }
            putpixel(x,y,WHITE);
        }
    }

}
int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,NULL);
    
    drawCircle(200,200,50);
    drawCircle(400,200,50);

    drawLine(200,200,401,201);
    

    cin>>gm;
    closegraph();
    return 0;
}
#include<iostream>
#include<graphics.h>

using namespace std;

void draw(int x,int y,int xc,int yc,int rad,int col){
    putpixel(x+xc,y+yc,col);
    putpixel(y+xc,x+yc,col);
    putpixel(-x+xc,y+yc,col);
    putpixel(-y+xc,x+yc,col);

    putpixel(x+xc,-y+yc,col);
    putpixel(y+xc,-x+yc,col);

    putpixel(-x+xc,-y+yc,col);
    putpixel(-y+xc,-x+yc,col);

}


int main()
{
    int gd=DETECT,gm;
    float x,y,xc=150,yc=150,rad=50,s;
    initgraph(&gd,&gm,NULL);
    x=0,y=rad;

    s=3-2*rad;
    while(x<y)
    {
        if(s<0){
            x++;
            s=s+4*x+6;
        }else{
            x++;
            y--;
            s=s+4*(x-y)+10;
        }
        draw(x,y,xc,yc,rad,WHITE);
        delay(10);
    }

    cin>>gm;
    closegraph();
    return 0;
}
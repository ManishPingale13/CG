#include<iostream>
#include<graphics.h>
using namespace std;

void plot(int x,int y,int xc,int yc,int COL){
    putpixel(x+xc,y+yc,COL);
    putpixel(y+xc,x+yc,COL);

    putpixel(-x+xc,-y+yc,COL);
    putpixel(-y+xc,-x+yc,COL);

    putpixel(-x+xc,y+yc,COL);
    putpixel(-y+xc,x+yc,COL);

    putpixel(x+xc,-y+yc,COL);
    putpixel(y+xc,-x+yc,COL);
    delay(50);
}

int main(){
    int gd=DETECT,gm;
    float x,y,p;
    initgraph(&gd,&gm,NULL);
    cout<<"enter circle x,y and radius\n";
    float xc[]={100,180,260,130,220};
    float yc[]={100,100,100,180,180};
    float col[]={BLUE,WHITE,RED,YELLOW,GREEN};
    float rad=50;

    for(int i=0;i<5;i++){
        rad=50;
        p=1-rad;
        x=0;
        y=rad;
        while(x<y){
            if(p<0){
                x++;
                p=p+(2*x)+1;   
            }else{
                x++;
                y--;    
                p=p+2*(x-y)+1;
            }
            plot(x,y,xc[i],yc[i],col[i]);
        }

    } 
    
    cin>>p;
    closegraph();
    return 0;
}
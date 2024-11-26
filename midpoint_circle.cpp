#include<iostream>
#include<graphics.h>
using namespace std;

void plot(int x,int y,int xc,int yc,int col){

    putpixel(-x+xc,-y+yc,col);
    putpixel(-y+xc,-x+yc,col);

    putpixel(x+xc,-y+yc,col);
    putpixel(y+xc,-x+yc,col);
    delay(5);
}

int main(){
    int gd=DETECT,gm;
    float x,y,xc=100,yc=100,rad[]={0,20,40,60},p;
    initgraph(&gd,&gm,NULL);
    int col[]={BLUE,GREEN,YELLOW,RED,0};
    for (int i = 0; i < 4; i++)
    {
        for (int j = rad[i]; j < rad[i]+20; j++)
        {
            p=1-j;
            x=0;
            y=j;
            while(x<y){
                if(p<0){
                    x++;
                    p=p+(2*x)+1;   
                }else{
                    x++;
                    y--;    
                    p=p+2*(x-y)+1;
                }
                plot(x,y,xc,yc,col[i]);
            }   
        }
        
             
    }


    cin>>p;
    closegraph();
    return 0;
}

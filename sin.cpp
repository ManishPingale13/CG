#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

/*
    line(0,200,640,200);
    for (int x = 0; x < 640; x++)
    {
         int y = (100 * sin((x * 3.14) / 180)) + 200;
        putpixel(x + 0, y, WHITE); // Draw the sine wave
        delay(5); // 
    }
    */

void plot(int x,int y,int xc,int yc){

    putpixel(-x+xc,-y+yc,RED);
    putpixel(-y+xc,-x+yc,RED);

    putpixel(x+xc,-y+yc,YELLOW);
    putpixel(y+xc,-x+yc,YELLOW);
    
    xc=xc+100;
    putpixel(x+xc,y+yc,WHITE);
    putpixel(y+xc,x+yc,WHITE);


    putpixel(-x+xc,y+yc,BLUE);
    putpixel(-y+xc,x+yc,BLUE);

    delay(50);
}

int main(){
    int gd=DETECT,gm;
    float xc[]={100,300,500},yc=100;    
    float rad=50,s,x,y;
    initgraph(&gd,&gm,NULL);
    
    for (int i = 0; i < 3; i++)
    {
        cout<<i<<endl;
        s=3-2*rad;
        x=0,y=rad;

        while(x<y){
            if(s<0){
                x++;
                s+=4*x+6;
            }else{
                x++;
                y--;
                s+=4*(x-y)+10;
            }
            plot(x,y,xc[i],yc);
        }
    }
    

    cin>>x;
    closegraph();
    return 0;
}
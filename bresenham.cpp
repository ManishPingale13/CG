#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

int main(){
    int gd=DETECT,gm;
    float x,y,x1,y1,x2,y2,dx,dy,p;
    initgraph(&gd,&gm,NULL);
    
    cout<<"Enter coordinates\n";
    cin>>x1>>y1>>x2>>y2;
    dx=x2-x1;
    dy=y2-y1;
    x=x1;
    y=y1;
    
    if(abs(dx)>abs(dy)){  //GENTLE
        p=(2*dy)-dx;

        while(x<x2){
            if(p<0){
                x+=1;
                y=y;
                p+=(2*dy);
            }else{
                x+=1;
                y+=1;
                p+=2*(dy-dx);
            }
            putpixel(x,y,WHITE);
            delay(50);
        }
    }else{        //STEEP
        p=(2*dx)-dy;
        
        while(x<x2){
            if(p<0){
                x=x;
                y+=1;
                p+=(2*dx);
            }else{
                x+=1;
                y+=1;
                p+=2*(dx-dy);
            }
            putpixel(x,y,WHITE);
            delay(50);
        }
    }


    delay(2000);
    closegraph();
    return 0;
}
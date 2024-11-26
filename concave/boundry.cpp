#include<iostream>
#include<graphics.h>
using namespace std;

void fill(int x,int y,int fillCol,int boundryCol){
    int col=getpixel(x,y);
    delay(1);
    if(col!=fillCol&&col!=boundryCol){
        putpixel(x,y,fillCol);
        fill(x+1,y,fillCol,boundryCol);
        fill(x-1,y,fillCol,boundryCol);
        fill(x,y+1,fillCol,boundryCol);
        fill(x,y-1,fillCol,boundryCol);
    }
}

int main(){
    int gd=DETECT,gm;
    int points[]={100,100,160,100,160,160,100,160,100,100};
    initgraph(&gd,&gm,NULL);
    drawpoly(5,points);
    fill(151,121,BLUE,WHITE);
    cin>>gm;
    closegraph();
    return 0;
}
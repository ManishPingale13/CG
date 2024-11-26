#include<iostream>
#include<graphics.h>
using namespace std;

void fill(int x,int y,int newCol,int oldCol){
    int col=getpixel(x,y);

    if(col==oldCol){
        putpixel(x,y,newCol);
        fill(x+1,y,newCol,oldCol);
        fill(x-1,y,newCol,oldCol);
        fill(x,y+1,newCol,oldCol);
        fill(x,y-1,newCol,oldCol);
    }
}
//CONCAVE angle>180
//CONVEX angle<180
int main(){
    int gd=DETECT,gm;
     int  points[] = {200, 200, 300, 100, 400, 200, 350, 300, 250, 250, 200, 200};
    initgraph(&gd,&gm,NULL);
    setcolor(RED);
    drawpoly(6,points);
    fill(202,200,BLUE,BLACK);
    cin>>gm;
    closegraph();
    return 0;
}
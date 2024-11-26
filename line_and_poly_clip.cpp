#include<iostream>
#include<graphics.h>
using namespace std;

const int xMin=100,yMin=100,xMax=300,yMax=300;

const int TOP=8;
const int BOTTOM=4;
const int RIGHT=2;
const int LEFT=1;

int compute_code(int x,int y)
{
    int code=0;
    if(y>yMax) code|=TOP;
    else if(y<yMin) code|=BOTTOM;

    if(x>xMax) code|=RIGHT;
    else if(x<xMin) code|=LEFT;

    return code;
}



void clip(int x1,int y1,int x2,int y2){
    int code1=compute_code(x1,y1);
    int code2=compute_code(x2,y2);
    while(true){
        //Completely inside
        if((code1|code2)==0)  {  
            cout<<"Line is inside";
            setcolor(GREEN);
            line(x1,y1,x2,y2);
            break;
        }

        //Completely outside
        else if(code1&code2){
            cout<<"Line in outside";
            break;
        }

        //Find intersection
        else{
            if(code1!=0){
                cout<<"Point 1 is out";
                int xc,yc;
                if(code1&TOP){
                    yc=yMax;
                    xc= x1+(x2-x1)*(yMax-y1)/(y2-y1);
                }if(code1&BOTTOM){
                    yc=yMin;
                    xc=x1+(x2-x1)*(yMin-y1)/(y2-y1);
                }if(code1&RIGHT){
                    xc=xMax;
                    yc=y1+(y2-y1)*(xMax-x1)/(x2-x1);
                }if(code1&LEFT){
                    xc=xMin;
                    yc=y1+(y2-y1)*(xMin-x1)/(x2-x1);
                }
                x1=xc;
                y1=yc;
                code1=compute_code(x1,y1);
            }
            if(code2!=0){
                cout<<"Point 2 is out";
                int xc,yc;
                if(code2&TOP){
                    yc=yMax;
                    xc= x1+(x2-x1)*(yMax-y1)/(y2-y1);
                }if(code2&BOTTOM){
                    yc=yMin;
                    xc=x1+(x2-x1)*(yMin-y1)/(y2-y1);
                }if(code2&RIGHT){
                    xc=xMax;
                    yc=y1+(y2-y1)*(xMax-x1)/(x2-x1);
                }if(code2&LEFT){
                    xc=xMin;
                    yc=y1+(y2-y1)*(xMin-x1)/(x2-x1);
                }
                x2=xc;
                y2=yc;
                code2=compute_code(x1,y1);
            }
        }
    }

}

int clipped_vertices[40];
int point_count;

void clip_poly(int x1,int y1,int x2,int y2){
    int code1=compute_code(x1,y1);
    int code2=compute_code(x2,y2);
    while(true){
        //Completely inside
        if((code1|code2)==0)  {  
            point_count+=4;
            cout<<point_count<<endl;
            clipped_vertices[point_count-4]=x1;
            clipped_vertices[point_count-3]=y1;
            clipped_vertices[point_count-2]=x2;
            clipped_vertices[point_count-1]=y2;
            break;
        }

        //Completely outside
        else if(code1&code2){
            cout<<"Line is outside";
            break;
        }

        //Find intersection
        else{
            if(code1!=0){
               
                int xc,yc;
                if(code1&TOP){
                    yc=yMax;
                    xc= x1+(x2-x1)*(yMax-y1)/(y2-y1);
                }if(code1&BOTTOM){
                    yc=yMin;
                    xc=x1+(x2-x1)*(yMin-y1)/(y2-y1);
                }if(code1&RIGHT){
                    xc=xMax;
                    yc=y1+(y2-y1)*(xMax-x1)/(x2-x1);
                }if(code1&LEFT){
                    xc=xMin;
                    yc=y1+(y2-y1)*(xMin-x1)/(x2-x1);
                }
                x1=xc;
                y1=yc;
                code1=compute_code(x1,y1);
            }
            if(code2!=0){
                int xc,yc;
                if(code2&TOP){
                    yc=yMax;
                    xc= x1+(x2-x1)*(yMax-y1)/(y2-y1);
                }if(code2&BOTTOM){
                    yc=yMin;
                    xc=x1+(x2-x1)*(yMin-y1)/(y2-y1);
                }if(code2&RIGHT){
                    xc=xMax;
                    yc=y1+(y2-y1)*(xMax-x1)/(x2-x1);
                }if(code2&LEFT){
                    xc=xMin;
                    yc=y1+(y2-y1)*(xMin-x1)/(x2-x1);
                }
                x2=xc;
                y2=yc;
                code2=compute_code(x1,y1);
            }
        }
    }

}


int main(){
    int gd=DETECT,gm;
    initgraph(&gd,&gm,NULL);
    
    int x1=100,y1=200,x2=400,y2=250;                         //Line points
    int points[]={80,80,160,80,360,160,80,160,80,80};  //Poly points
    int total_points=10; // 5 vertices = 10 i.e. 2x points

    setcolor(WHITE);
    rectangle(xMin,yMin,xMax,yMax);                         //Clipping window
    
    setcolor(RED);
    drawpoly(total_points/2,points);                                     //Overall poly in RED

    //Clip poly using line clipping
    point_count=0;
    for (int i = 0; i < total_points; i+=2)
    {
        clip_poly(points[i],points[i+1],points[(i+2)%total_points],points[(i+3)%total_points]);
    }
    

    //Set clipped poly color to blue 
    for (int i = 0; i < point_count; i+=2)
    {
        cout<<"clipped_vertices: ("<<clipped_vertices[i]<<","<<clipped_vertices[i+1]<<")"<<endl;
    
    }
    setcolor(BLUE);
    drawpoly(point_count/2,clipped_vertices);
    line(clipped_vertices[point_count-2],clipped_vertices[point_count-1]
    ,clipped_vertices[0],clipped_vertices[1]);          //last line
    

    
    /*
    //Line clipping code
    setcolor(RED);
    line(x1,y1,x2,y2);
    clip(x1,y1,x2,y2);
    
    */


    cin>>gm;
    closegraph();
    return 0;
}

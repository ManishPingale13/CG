#include<graphics.h>
#include<iostream>
using namespace std;

class Transformations{
    public:
        int n;
        int xMax,yMax;
        int xMid,yMid;
        int x[10],y[10];

        void drawAxis(){
           
            xMax=getmaxx();
            yMax=getmaxy();
            xMid=xMax/2;
            yMid=yMax/2;

            line(0,yMid,xMax,yMid);
            line(xMid,0,xMid,yMax);
        }

        void input(){
            cout<<"Enter number of vertices:\n";
            cin>>n;
            cout<<"Enter Coordinates:\n";
            for(int i=0;i<n;i++){
                cin>>x[i];
                cin>>y[i];
            }
            this->output(x,y);
        }

        void output(int x[],int y[]){
            for (int i = 0; i < n; i++)
            {
                line(x[i]+xMid,         yMid-y[i]
                    ,x[(i+1)%n]+xMid,   yMid-y[(i+1)%n]);
            }
            
        }

        void translate(){
            int tx,ty;
            cout<<"Enter Tx and Ty\n";
            cin>>tx>>ty;
            int x1[15],y1[15];

            for (int i = 0; i < n; i++)
            {
                x1[i]=x[i]+tx;
                y1[i]=y[i]+ty;
            }
            this->output(x1,y1);
            
        }

        void scale(){
            float sX,sY;
            int x1[15],y1[15];
            cout<<"Enter Sx,Sy\n";
            cin>>sX>>sY;

            for (int i = 0; i < n; i++)
            {
                x1[i]=x[i]*sX;
                y1[i]=y[i]*sY;

            }
            this->output(x1,y1);
        }

        void rotate(){
            float rad;
            cout<<"Enter angle\n";
            cin>>rad;
            rad=(rad*3.14)/180;
            int x1[15],y1[15];
            for (int i = 0; i < n; i++)
            {
                x1[i]=x[i]*cos(rad)-sin(rad)*y[i];
                y1[i]=x[i]*sin(rad)+y[i]*cos(rad);
            }
            
            this->output(x1,y1);
            
        }
};

int main(){
    int gd=DETECT,gm;
    char ch;
    initgraph(&gd,&gm,NULL);

    Transformations ts;
    ts.drawAxis();
    ts.input();
    
    ts.translate();

    ts.scale();

    ts.rotate();

    cin>>ch;
    closegraph();
    return 0;
}
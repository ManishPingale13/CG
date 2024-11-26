#include<graphics.h>
#include<iostream>
using namespace std;

class Transform{
    public:
        int midX,midY,maxX,maxY;
        int x[15],y[15],n;
    void drawAxis(){
        maxX=getmaxx();
        maxY=getmaxy();
        midX=maxX/2;
        midY=maxY/2;
        line(0,midY,maxX,midY);
        line(midX,0,midX,maxY);
    }
    void input(){
        cout<<"Enter vertices";
        cin>>n;
        cout<<"Enter coordinates";
        for (int i = 0; i < n; i++)
        {
            cin>>x[i];
            cin>>y[i];
        }
        this->output(x,y);
    }
    void output(int x[],int y[]){
        for (int i = 0; i < n; i++)
        {
            line(midX+x[i],midY-y[i],midX+x[(i+1)%n],midY-y[(i+1)%n]);
        }
        
    }

    void translate(){
        int tx,ty;
        cout<<"Enter tx,ty";
        cin>>tx>>ty;
        int x1[15],y1[15];
        for (int i = 0; i < n; i++)
        {
            x1[i]=x[i]+tx;
            y1[i]=y[i]+ty;
        }
        this->output(x1,y1);
        
    }

    void rotate(){
        float theta;
        cout<<"Enter theta";
        cin>>theta;
        theta=(theta*3.14)/180;

        int x1[15],y1[15];
        for (int i = 0; i < n; i++)
        {
            x1[i]=x[i]*cos(theta)-sin(theta)*y[i];
            y1[i]=sin(theta)*x[i]+cos(theta)*y[i];
        }
        this->output(x1,y1);
        
    }

    void shear(){
        int shX,shY;
        cout<<"Enter shX,shY";
        cin>>shX>>shY;
        int x1[15],y1[15];
        for (int i = 0; i < n; i++)
        {
            x1[i]=x[i]+shX*y[i];
            y1[i]=y[i]+shY*x[i];
        }
        this->output(x1,y1);
        
    }   

    void reflectAbtX(){
        int x1[15],y1[15];
        for (int i = 0; i < n; i++)
        {
            x1[i]=x[i];
            y1[i]=-y[i];
        }
        this->output(x1,y1);
    }
};

int main(){
    int gd=DETECT,gm;
    initgraph(&gd,&gm,NULL);
    Transform t;
    t.drawAxis();
    t.input();

    t.translate();

    t.rotate();

    t.shear();

    t.reflectAbtX();
    cin>>gm;
    closegraph();
    return 0;
}
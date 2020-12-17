#include<iostream>
#include<cstdio>

using namespace std;

struct CircleParameter { int x,y,r;};

void DrawMidPointCircle(CircleParameter);
void ShowPoint(int,int);

int main()
{

    CircleParameter CP;
    cout<<"Enter the radius"<<endl;
    cin>>CP.r>>CP.x>>CP.y;
    DrawMidPointCircle(CP);
    return 0;
}


void DrawMidPointCircle(CircleParameter CP)
{
    float p=5./4-CP.r;
    int x=0,y=CP.r;
    ShowPoint(x,y); cout<<"  "<<p<<endl;
    do
    {
        int t=y;
        if(p>0) y--;
        p=p+2*x+1+(y*y-t*t)-(y-t); //decision parameter
        x++;
        ShowPoint(x,y); cout<<"  "<<p<<endl;
    }while(y>=x);
}


void ShowPoint(int x,int y)
{
    cout<<"("<<x<<","<<y<<")";
}


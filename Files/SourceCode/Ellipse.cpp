#include<iostream>
#include<cstdio>
using namespace std;

struct Ellipse {int h,k,a,b;};

istream& operator>>(istream&,Ellipse&);

void ShowPoint(Ellipse,int,int);
void BreshenhamEllipse(Ellipse);
void PartEllipse(Ellipse,int=0);

template <typename DataType>
void Swap(DataType&,DataType&);

int main()
{
    Ellipse E;
    cin>>E;
    BreshenhamEllipse(E);
    return 0;
}

void BreshenhamEllipse(Ellipse E)
{
    PartEllipse(E);
    Swap(E.a,E.b);
    PartEllipse(E,1);
}
void PartEllipse(Ellipse E,int SwapIndex)
{
    int B=E.b*E.b,A=E.a*E.a; // A=a^2 and B=b^2 squares of semi major and minor axes resp.
    float p=B-(A*E.b)+A/4.;  //initial decision parameter
    int x=0,y=E.b;  //starting point to plot.
    do
    {
        if(SwapIndex==0) ShowPoint(E,x,y); else ShowPoint(E,y,x);cout<<endl;
        int t=y; //preserve y_k to calculate p_{k+1}
        if(p>0) y--; //decide between updating y coordinate
        p=p+2*B*x+B+A*(y+t-1)*(y-t);//recursive formula for decision parameter
        x++; //always increase x coordinate by just 1;
    }
    while(B*x<=A*y); //loop while the points are within the limit of slope.
}
void ShowPoint(Ellipse E,int x,int y)
{
	cout<<"("<<E.h+x<<","<<E.k+y<<")";
}


istream& operator>>(istream&ip,Ellipse&E)
{
    cout<<"Enter the centre coordinates     - : "; cin>>E.h>>E.k;
    cout<<"Enter semi-major and-minor axes  - : "; cin>>E.a>>E.b;
    return ip;
}

template <typename DataType>
void Swap(DataType& p1,DataType&p2)
{
    DataType p;
    p=p1;
    p1=p2;
    p2=p;
}



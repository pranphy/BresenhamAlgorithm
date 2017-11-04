#include<iostream>

using namespace std;

struct Point
{
    int x,y;
};
struct Line
{
    Point InitialPoint, FinalPoint;
};

ostream& operator<<(ostream&,Point);
istream& operator>>(istream&,Point&);
istream& operator>>(istream&,Line&);

Point operator+(Point,Point);
Point operator-(Point,Point);
int AnalyzePoint(Point);
Point ProperPoint(Point,int);

template <typename DataType>
void Swap(DataType&,DataType&);

int main()
{
    Line BreshenhamLine;
    cin>>BreshenhamLine;
    Point P=BreshenhamLine.FinalPoint-BreshenhamLine.InitialPoint;
    int d=AnalyzePoint(P);
    P=ProperPoint(P,d);
    d=(d==7?3:d==3?7:d);
    Point CurrentPoint={0,0};
    int p=2*P.y-P.x;
    do
    {
        cout<<p<<"   -->  "<<BreshenhamLine.InitialPoint+ProperPoint(CurrentPoint,d)<<endl;
        int t=CurrentPoint.y;
        if(p>0) CurrentPoint.y++;
        p=p+2*P.y-2*P.x*(CurrentPoint.y-t);
        CurrentPoint.x++;
    }
    while(CurrentPoint.x<=P.x);
    return 0;
}
Point operator+(Point P1,Point P2)
{
    Point P;
    P.x=P1.x+P2.x;
    P.y=P1.y+P2.y;
    return P;
}

Point operator-(Point P1,Point P2)
{
    Point P;
    P.x=P1.x-P2.x;
    P.y=P1.y-P2.y;
    return P;
}

ostream& operator<<(ostream& op,Point p)
{
    cout<<"("<<p.x<<","<<p.y<<")";
    return op;
}

istream& operator>>(istream& ip,Point&p)
{
    cin>>p.x>>p.y;
    return ip;
}

istream& operator>>(istream& ip, Line& L)
{
    cout<<"Enter first point ";
    cin>>L.InitialPoint;
    cout<<"Enter last  point ";
    cin>>L.FinalPoint;
}
int AnalyzePoint(Point P)
{

    if(P.x>=0)
        if(P.y>=0)
            return (P.y>P.x?2:1);
        else
            return (-P.y<P.x?8:7);
    else
        if(P.y>0)
            return (P.y>-P.x?3:4);
        else
            return(-P.y>-P.x?6:5);
}

template <typename DataType>
void Swap(DataType& p1,DataType&p2)
{
    DataType p;
    p=p1;
    p1=p2;
    p2=p;
}

Point ProperPoint(Point P,int d)
{

    if(d==2||d==3||d==6||d==7)
         Swap(P.x,P.y);
    if(d==7||d==4||d==5||d==6)
         P.x*=-1;
    if(d==3||d==8||d==5||d==6)
         P.y*=-1;
    return P;
}


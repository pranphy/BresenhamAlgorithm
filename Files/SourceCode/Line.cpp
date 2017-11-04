#include<iostream>
using namespace std;
struct Point {int x,y;};

ostream& operator<<(ostream&,Point);
istream& operator>>(istream&,Point&);

Point operator+(Point,Point);
Point operator-(Point,Point);
int FindOctant(Point);
Point ProperPoint(Point,int);
void BreshenhamLine(Point,Point);

template <typename DataType>
void Swap(DataType&,DataType&);

int main()
{
    Point InitialPoint,FinalPoint;
    cin>>InitialPoint>>FinalPoint;
    BreshenhamLine(InitialPoint,FinalPoint);
    return 0;
}

void BreshenhamLine(Point InitialPoint,Point FinalPoint)
{
    Point P=FinalPoint-InitialPoint; //transfer origin
    int OctantIndex=FindOctant(P);
    P=ProperPoint(P,OctantIndex); //transform point
    OctantIndex=(OctantIndex==7?3:(OctantIndex==3)?7:OctantIndex); //fooling around you see?
    Point CurrentPoint={0,0};
    int p=2*P.y-P.x;
    do
    {
        cout<<InitialPoint+ProperPoint(CurrentPoint,OctantIndex)<<endl; //transfer origin back
        int t=CurrentPoint.y;
        if(p>0) CurrentPoint.y++;
        p=p+2*P.y-2*P.x*(CurrentPoint.y-t);
        CurrentPoint.x++;
    }
    while(CurrentPoint.x<=P.x);
}

int FindOctant(Point P)
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

istream& operator>>(istream&ip,Point&p)
{
    cout<<" Enter point"; cin>>p.x>>p.y;
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



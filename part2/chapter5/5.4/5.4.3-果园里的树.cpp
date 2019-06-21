#include<iostream>
using namespace std;
double area2(double x0,double y0,double x1,double y1,double x2,double y2){
    return abs(x0*y1+x2*y0+x1*y2-x2*y1-x0*y2-x1*y0);}
int main()
{
    double x0,y0,x1,y1,x2,y2;
    const double eps=1e-9;
    while(cin>>x0>>y0>>x1>>y1>>x2>>y2){
        double area=area2(x0,y0,x1,y1,x2,y2);
        int count=0;
        for(int i=1;i<=99;i++)
        for(int j=1;j<=99;j++){
            double a1,a2,a3;
            a1=area2(i,j,x0,y0,x1,y1);
            a2=area2(i,j,x0,y0,x2,y2);
            a3=area2(i,j,x1,y1,x2,y2);
            if(fabs(a1+a2+a3-area)<eps) count++;
        }    
        cout << count << endl;
    }    
    return 0;
} 

#include<iostream>
#include<cstdio>
using namespace std;
double abs(double a){if(a>=0) return a; else return -a;}
#define INF 0.000001
int main()
{
 freopen("approximation.out","w",stdout);
 double p,a;
 int i=1,fh=-1;
 p=a=1;
 //printf("a=%lf\n10e-6=%.6lf",a,0.000001);
 while(abs(a)>=INF)
 {
  //cout << "1/"<<i<<"=" <<a << endl;
  i+=2;
  //cout << fh<<i << endl;
  a=double(fh)/i;
  //cout << a << endl;
  p+=a;
  fh=-fh;
 }
 printf("%.6lf\n",p);
 return 0;
}

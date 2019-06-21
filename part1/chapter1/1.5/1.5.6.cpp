#include<iostream>
#include<stdio.h>
#include<math.h>
#include<iomanip>
using namespace std;
void average(){
  int a,b,c;
  scanf("%d%d%d",&a,&b,&c);
  printf("%.3lf\n",double(a+b+c)/3);
}
void temperature()
{
 int f;
 double c;
 cin >> f;
 c=5*(double(f)-32)/9;
 //printf("%lf\n",c);
 cout <<setiosflags(ios::fixed) << setprecision(3) << c<< endl;
}
void sum()
{
 int n;
 scanf("%d",&n);
 printf("%d\n",n*(1+n)/2);
}
void sincos()
{
   //1-4
   const double pi=atan(1)*4;
   int n;
   scanf("%d",&n);
   printf("sin(%d)=%lf,cos(%d)=%lf\n",n,sin(pi*n/180)+0.0000001,n,cos(pi*n/180)+0.0000001);
}
void distance()
{
   //1-5
   double x1,y1,x2,y2;
   scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
   printf("%lf",sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)));
}
void odd()
{
   int n;
   scanf("%d",&n);
   printf("%s",n%2?"no":"yes");
}
void discount()
{
   int n;
   cin>> n ;
   double ans=n*95;
   if(floor(ans+0.5)>300) ans*=0.85;
   cout << setiosflags(ios::fixed) << setprecision(2) << ans << endl ;
}
void abs(){
  int a;
  cin >> a;
  cout << (a > 0 ? a : - a) ;
}
void triangle()
{
  int a,b,c,t;
  cin >> a >> b >> c;
  if(a>b) {t=a; a=b; b=t;}
  if(b>c) {t=b; b=c; c=t;}
  if(a>b) {t=a; a=b; b= t;}
  if(a+b>c&&c-b<a){
  if(a*a+b*b==c*c) cout << "yes"; else  cout << "no";}
  else cout << "not a triangle";
  cout << endl;
}
void year()
{
   int n;
   cin >> n;
   if((n%4==0&&n%100!=0)||(n%400==0)) cout << "yes"; else cout <<"no";
}
int main()
{
    //average();
    //temperature();
    //sum();
    //sincos();
    //distance();
    //odd();
    //discount();
    //abs();
    //triangle();
    //year();
    return 0;
}

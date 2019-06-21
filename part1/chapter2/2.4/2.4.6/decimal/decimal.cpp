#include<iostream>
#include<cstdio>
#define FILE
using namespace std;
int main()
{
 int a,b,c;
 #ifdef FILE
 freopen("decimal.in","r",stdin);
 freopen("decimal.out","w",stdout);
 #endif
 scanf("%d%d%d",&a,&b,&c);
 printf("%d.",a/b);
 a=a%b*10;
 int d=1,x;
 while(d<=c)
 {
  x=a/b;
  if(d==c) printf("%d",(a%b*10)/b>=5?x+1:x);  //注意末位四舍五入
  else printf("%d",x);
  a=a%b*10;
  d++;
 }
 return 0;
}

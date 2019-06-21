#include<cstdio>
#include<cmath>
#include<cassert>
bool isprime(int x)
{
 assert(x>=0);
 if(x<2) return false;
 if(x==2) return true;
 int m=floor(sqrt(x)+0.5);
 for(int i=2;i<=m;i++) if(x%i==0) return false;
 return true;
}
int main()
{
 int m;
 scanf("%d",&m);
 for(int i=m-2;i>=3;i--) if(isprime(i)&&isprime(i+2)) {printf("%d,%d\n",i,i+2); break;}
 return 0;
}

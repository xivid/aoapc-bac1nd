#include<iostream>
#include<cassert>
#include<cstdio>
using namespace std;
int f(int x)
{
 assert(x >= 0);

 if(x==0) return 0;
 int s=1;

 for(int i=1;i<=x;i++) {s*=i;assert(s >= 0);}

 return s;
}
int main()
{
 int n;
 scanf("%d",&n);
 printf("%d\n",f(n));
 return 0;

}

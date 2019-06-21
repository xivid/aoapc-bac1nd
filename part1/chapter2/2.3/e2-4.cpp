#include<iostream>
#include<cstdio>
using namespace std;
#define MOD 1000000
int main()
{
  int min,max,sum=0,n=0,t;
  scanf("%d",&t); {min=max=t; sum+=t; n++;}
  freopen("e2-4.in","r",stdin);
  freopen("e2-4.out","w",stdout);
  while(scanf("%d",&t)==1)
  {
   if(min>t) min=t;
   if(max<t) max=t;
   sum+=t; n++;
  }
  printf("Min:%d Max:%d Sum:%d n:%d Average:%.3lf\n",min,max,sum,n,(double)sum/n);

  return 0;
}

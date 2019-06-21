#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
 freopen("subsequence.in","r",stdin);
 freopen("subsequence.out","w",stdout);
 int n,m;
 double s=0;
 scanf("%d%d",&n,&m);
 for(int i=n;i<=m;i++) s+=1/(double)((long long)i*i);
 printf("%.5lf\n",s);
 return 0;
}

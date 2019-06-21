#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
 freopen("harmony.in","r",stdin);
 freopen("harmony.out","w",stdout);
 int n;
 double s=0;
 cin >> n;
 for(int i=1;i<=n;i++)
 {
    s+=(double)1/i;
 }
 printf("%.3lf\n",s);
 return 0;
}

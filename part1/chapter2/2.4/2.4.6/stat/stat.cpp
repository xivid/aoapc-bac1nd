#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define MAXN 10000
int main()
{
 freopen("stat.in","r",stdin);
 freopen("stat.out","w",stdout);
 int n,a[MAXN],t,ans=0;
 memset(a,0,sizeof(a));
 cin >> n;
 for(int i=1;i<=n;i++)
 {
  cin >> t;
  a[ t] ++;
 }
 cin >> t;
 for(int i=1;i<t;i++) ans+=a[i];
 cout << ans << endl;
}

#include<iostream>
#include<cstdio>
using namespace std;
#define MOD 1000000
int main()
{
 int n; int  s=0,f=1;
 cin >> n;
 if(n>24) n=24;
 for(int i=1;i<=n;i++)
 {
  f=f*i%MOD;
  s=(s+f)%MOD;
 }
 s%=MOD;
 cout << s;
 return 0;
}

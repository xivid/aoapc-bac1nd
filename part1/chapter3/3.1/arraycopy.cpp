#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
 int a[10],b[10];
 for(int i=0;i<10;i++) cin >> a[i];
 memset(b,0,sizeof(b));
 memcpy(b,a,sizeof(a));
 for(int i=0;i<10;i++) cout << a[i];
 return 0;
}

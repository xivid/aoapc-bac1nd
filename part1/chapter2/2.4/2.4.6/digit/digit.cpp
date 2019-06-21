#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
 freopen("digit.in","r",stdin);
 freopen("digit.out","w",stdout);
 int n,d=0;
 cin >> n;
 while(n) {n/=10; d++;}
 cout << d << endl;
}

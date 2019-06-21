#include<iostream>
#include<stdio.h>
#include<cstdlib>
using namespace std;
int main()
{
 long long n,ans=0;
 cin >> n;

 while(n!=1)
 {
  if(n%2) n=3*n+1;
  else n/=2;
  ans++;
 }

 cout << ans << endl;
 return 0;
}

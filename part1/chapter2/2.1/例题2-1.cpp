#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
 int i,a,b,c,d,s;
 for(i=30;;i++)
 {
  if((s=i*i)<1000) continue;
  if(s>9999) break;
  a=s/1000; b=s/100%10; c=s/10%10; d=s%10;
  if(a==b&&c==d) cout << s << endl;
 }
 return 0;
}

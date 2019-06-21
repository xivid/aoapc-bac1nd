//uva可以再坑爹点吗？直接说做n（n<=100）个高精度(len<=100)的加法会死？
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int a[120],b[120];
int main()
{
  string s;
  memset(a,0,sizeof(a));
  for(;;)
  {
    cin >> s;
    if(s[0]=='0'&&s.length()==1) break;
    int l=s.length();
    memset(b,0,sizeof(b));
    for(int i=1;i<=l;i++) b[i]=s[l-i]-'0';
    for(int i=1;i<=110;i++) {a[i]+=b[i]; a[i+1]+=a[i]/10; a[i]%=10; }
  }
  int i;
  for(i=110;a[i]==0&&i>1;i--);
  for(;i>0;i--) cout << a[i];
  cout << endl;
}

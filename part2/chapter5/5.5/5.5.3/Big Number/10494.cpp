#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
  long long a[1000];
  long long b;
  char s[1000],c;
  for(;;)
  {
    memset(a,0,sizeof(a));
    if(scanf("%s",s)==EOF) break;
    while(c=getchar()) if(c=='/'||c=='%') break;
    cin >> b;
    int len=strlen(s);
    for(int i=1;i<=len;i++) a[i]=s[len-i]-'0';
    //教训：再一次忘记删除调试信息
    long long y=0;
    for(int i=len;i>0;i--)
    {
      a[i]=y*10+a[i];
      y=a[i]%b;
      a[i]/=b;
    }
    if(c=='/')
    {
      for(;a[len]==0&&len>0;len--);
      for(int i=len;i>0;i--) cout << a[i];
    }
    else cout << y;
    cout << endl;
  }
  return 0;
}
/*
The first one may be arbitrarily long. The second number n will be in the range (0 < n < 231).
num1(space(s))(sign)(space(s))num2
Sample Input
110 / 100
99 % 10
2147483647 / 2147483647
2147483646 % 2147483647
Sample Output
1
9
1
2147483646
*/

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
long long a[1000000];
long long b;
char s[1000000],c;
int main()
{
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
      for(;a[len]==0&&len>1;len--); //除0时一定要注意不要除掉最后的0，以免无输出！！已在此处多次犯错！！（P.S.对拍真是神器！）
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

#include<cstdio>
#include<cstdlib>
#include<cstring>
void cheng(int a[],int x)
{
  for(int i=1;i<=550;i++) a[i]=a[i]*x;
  for(int i=1;i<=550;i++) {a[i+1]+=a[i]/10; a[i]%=10;}
}
int main()
{
  char r[10];
  int n;
  while(scanf("%s%d",r,&n)==2)
  {
    int a[600],len=0,b=0,point,ws=0;
    memset(a,0,sizeof(a));
    while(r[strlen(r)-1-ws]=='0') ws++; //错误1
    ws*=n;
    for(int i=strlen(r)-1;i>=0;i--) if(r[i]>='0'&&r[i]<='9') a[++len]=r[i]-'0'; else point=n*(5-i);
    for(int i=len;i>0;i--) b=b*10+a[i];
    for(int i=2;i<=n;i++) cheng(a,b);
    for(len=550;len>1&&!a[len];len--);
    if(point>=len)
    {
      putchar('.');
      for(int i=1;i<=point-len;i++) putchar('0');
      for(int i=len;i>0;i--) printf("%d",a[i]);
      putchar('\n');
    }
    else
    {
      for(int i=len;i>point;i--) printf("%d",a[i]);
      if(point>ws) putchar('.'); //错误2
      for(int i=point;i>ws;i--) printf("%d",a[i]);
      putchar('\n');
    }
  }
  return 0;
}
/*
//从网上找了AC程序，对拍了好几次，改了几个小错误，终于也AC了
 Sample Input

95.123 12
0.4321 20
5.1234 15
6.7592  9
98.999 10
1.0100 12

Sample Output

548815620517731830194541.899025343415715973535967221869852721
.00000005148554641076956121994511276767154838481760200726351203835429763013462401
43992025569.928573701266488041146654993318703707511666295476720493953024
29448126.764121021618164430206909037173276672
90429072743629540498.107596019456651774561044010001
1.126825030131969720661201
*/

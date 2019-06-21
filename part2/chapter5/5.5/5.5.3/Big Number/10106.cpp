//high times high
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
int main()
{
  int a[1000],b[1000],c[1000],la,lb,lc;
  char s[1000];
  int flag=0;
  while(scanf("%s",s)!=EOF)
  {
    if(!flag) {
      memset(a,0,sizeof(a)); memset(b,0,sizeof(b)); memset(c,0,sizeof(c));
      la=strlen(s);
      for(int i=1;i<=la;i++) a[i]=s[la-i]-'0';
      //printf("a=");
      //for(int i=la;i>0;i--) printf("%d",a[i]);
      //printf("\n");
      flag=!flag;
      continue;
      }
    else
    {
      lb=strlen(s);
      for(int i=1;i<=lb;i++) b[i]=s[lb-i]-'0';
      //printf("b=");
      //for(int i=lb;i>0;i--) printf("%d",b[i]);
      //printf("\n");
      for(int i=1;i<=la;i++)
       for(int j=1;j<=lb;j++)
        c[i+j-1]+=a[i]*b[j];
      lc=la+lb;
      //printf("lc=%d\n",lc);
      for(int i=1;i<=lc;i++) {c[i+1]+=c[i]/10; c[i]%=10;}
      for(;lc>1&&c[lc]==0;lc--);
      for(int i=lc;i>0;i--) printf("%d",c[i]);
      putchar('\n');
      flag=!flag;
    }
  }
  return 0;
}

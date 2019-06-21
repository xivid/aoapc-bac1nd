#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cctype>
#define MAXN 5000 + 10
using namespace std;
int main()
{
   char s[MAXN],buf[MAXN];
   int p[MAXN],len,m=0,max=0,x,y;
   memset(p,0,sizeof(p));
   fgets(s,sizeof(s),stdin);
   len=strlen(s);
   for(int i=0;i<len;i++) if(isalpha(s[i])) {p[m]=i; buf[m++]=toupper(s[i]);}
   for(int i=0;i<m;i++){
      for(int j=0;i-j>=0&&i+j<m;j++){ //jishu
        if(buf[i-j]!=buf[i+j]) break;
        if(2*j+1>max){ max=2*j+1; x=i-j; y=i+j; }
      }
      for(int j=0;i-j>=0&&i+j+1<m;j++){ //oushu
        if(buf[i-j]!=buf[i+j+1]) break;
        if(2*j+2>max){ max=2*j+2; x=i-j; y=i+j+1;}
      }
   }
   for(int i=p[x];i<=p[y];i++) printf("%c",s[i]);
   printf("\n");
   return 0;
}

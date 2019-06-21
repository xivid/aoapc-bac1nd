#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int main()
{
   int abc,de,x,y,ans,count,len,i,ok;
   char s[20],buf[50];
   scanf("%s",s);
   count=0;
   for(abc=100;abc<=999;abc++)
    for(de=10;de<=99;de++){
     x=abc*(de%10); y=abc*(de/10); ans=abc*de;
     sprintf(buf,"%d%d%d%d%d",abc,de,x,y,ans);
     len=strlen(buf);
     ok=1;
     for(i=0;i<len;i++) if(strchr(s,buf[i])==NULL) ok=0;
     if(ok) {count++; printf("<%d>\n%5d\nX%4d\n-----\n%5d\n%4d\n-----\n%5d\n\n",count,abc,de,x,y,ans); }
     getchar();
    }
   printf("The number of solutions = %d.\n",count);
   return 0;
}

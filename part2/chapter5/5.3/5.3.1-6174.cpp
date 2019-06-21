#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int getnext(int x){
 int next,a,b,len;
 char s[10];
 sprintf(s,"%d",x);
 len=strlen(s);
 for(int i=0;i<len;i++)
  for(int j=len-1;j>i;j--)
   if(s[j]>s[j-1]) {char t=s[j]; s[j]=s[j-1]; s[j-1]=t; }
 sscanf(s,"%d",&a);
 for(int i=0;i<len/2;i++) {char t=s[i]; s[i]=s[len-1-i]; s[len-1-i]=t;}
 sscanf(s,"%d",&b);
 next=a-b;
 return next;
}
int get_next(int x){
 int next,a,b,len;
 char s[10];
 sprintf(s,"%d",x);
 len=strlen(s);
 for(int i=0;i<len;i++)
  for(int j=i+1;j<len;j++)
   if(s[j]>s[i]) {char t=s[j]; s[j]=s[i]; s[i]=t; }
 sscanf(s,"%d",&a);
 for(int i=0;i<len/2;i++) {char t=s[i]; s[i]=s[len-1-i]; s[len-1-i]=t;}
 sscanf(s,"%d",&b);
 next=a-b;
 return next;
}
int main()
{
 int path[1010],count=0,found=0;
 memset(path,0,sizeof(path));
 scanf("%d",&path[++count]);
 printf("%d",path[count]);
 do{
  path[count+1]=getnext(path[count]);
  count++;
  printf("->%d",path[count]);
  found=0;
  for(int i=1;i<count;i++) if(path[i]==path[count]) {found=1; break;}
 }while(!found&&count<=1000);
 printf("\n");
 //for(int i=1;i<=count;i++) cout << path[i];
 return 0;
}

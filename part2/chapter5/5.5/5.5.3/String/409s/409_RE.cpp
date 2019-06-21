//乱写一通，Runtime Error，作废重写
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<sstream>
#include<string>
#include<iostream>
using namespace std;
int k,e,set=0;
int check(char ex[],char dict[][30])
{
 int ans=0;
 string es(ex);
 stringstream ss(es);
 char now[30];
 while(ss >> now)
 {
  for(int i=1;i<=k;i++)
   if(!strcmp(now,dict[i])) {ans++; break;}
 }
 return ans;
}
int main()
{
 while(scanf("%d%d",&k,&e)==2)
 {
  set++;
  int max=-1,s[30],n=0;
  char dict[30][30];
  char ex[30][80],tex[30][80];
  for(int i=1;i<=k;i++) scanf("%s",dict[i]);
  for(int i=1;i<=e;i++)
  {
   char c;
   int l=0;
   c=getchar();
   if(c=='\n') c=getchar();
   do
   {tex[i][l]=c;
    if(isalpha(c)) {if(isupper(c)) ex[i][l]=tolower(c); else ex[i][l]=c;}
    else ex[i][l]=' ';
    l++;
   }while((c=getchar())!='\n');
   ex[i][l]='\0';
   int num=check(ex[i],dict);
   if(num>max) {max=num; s[n=1]=i;}
   else if(num==max) s[++n]=i;
  }
  printf("Excuse Set #%d\n",set);
  for(int i=1;i<=n;i++) {puts(tex[s[i]]); }
  putchar('\n');
 }
 return 0;
}
/*
Sample Input

5 3
dog
ate
homework
canary
died
My dog ate my homework.
Can you believe my dog died after eating my canary... AND MY HOMEWORK?
This excuse is so good that it contain 0 keywords.
6 5
superhighway
crazy
thermonuclear
bedroom
war
building
I am having a superhighway built in my bedroom.
I am actually crazy.
1234567890.....,,,,,0987654321?????!!!!!!
There was a thermonuclear war!
I ate my dog, my canary, and my homework ... note outdated keywords?

Sample Output

Excuse Set #1
Can you believe my dog died after eating my canary... AND MY HOMEWORK?

Excuse Set #2
I am having a superhighway built in my bedroom.
There was a thermonuclear war!
*/

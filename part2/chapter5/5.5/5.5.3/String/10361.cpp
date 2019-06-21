#include<cstring>
#include<cstdio>
#include<cstdlib>
int main()
{
 int cases;
 char s1[200],s2[200];
 scanf("%d\n",&cases);
 while(cases--)
 {
  fgets(s1,200,stdin);
  fgets(s2,200,stdin);
  s1[strlen(s1)-1]='\0';
  s2[strlen(s2)-1]='\0';
  int l1=-1,l2=-1,r1=-1,r2=-1,l=strlen(s1),ll=strlen(s2);
  for(int i=0;i<l;i++)
  {
   if(s1[i]=='<')
    if(l1<0) l1=i;
    else l2=i;
   else if(s1[i]=='>')
    if(r1<0) r1=i;
    else r2=i;
   else putchar(s1[i]);
  }
  putchar('\n');
  //s1<s2>s3<s4>s5
  //instead of the three dots the string s4s3s2s5 should appear
  for(int i=0;i<ll&&s2[i]!='.';i++) putchar(s2[i]);
  for(int i=l2+1;i<r2;i++) putchar(s1[i]);
  for(int i=r1+1;i<l2;i++) putchar(s1[i]);
  for(int i=l1+1;i<r1;i++) putchar(s1[i]);
  for(int i=r2+1;i<l;i++) putchar(s1[i]);
  putchar('\n');
 }
 return 0;
}
/*
Sample Input
3
ein kind haelt seinen <schn>abel <n>ur
wenn es haengt an der ...
weil wir zu spaet zur <>oma <k>amen
verpassten wir das ...
<d>u <b>ist
...

Sample Output
ein kind haelt seinen schnabel nur
wenn es haengt an der nabel schnur
weil wir zu spaet zur oma kamen
verpassten wir das koma amen
du bist
bu dist
*/

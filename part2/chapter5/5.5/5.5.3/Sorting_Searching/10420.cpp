#include<cstdio>
#include<cstdlib>
#include<cstring>
char name[2010][80];
int s[2010];
int n,tot=0;
int main()
{
  char buf[80],country[80];
  int flag=1;
  memset(s,0,sizeof(s));
  scanf("%d\n",&n);
  for(int i=1;i<=n;i++)
  {
    gets(buf);
    sscanf(buf,"%s",country);
    flag=1;
    for(int j=1;j<=tot;j++) if(!strcmp(country,name[j])) {s[j]++; flag=0; break;}
    if(flag) {strcpy(name[++tot],country); s[tot]=1;}
  }
  for(int i=1;i<tot;i++) {
   int k=i;
   for(int j=k;j<=tot;j++)  if(strcmp(name[j],name[k])<0) k=j;
   if(k!=i){
   char t[80]; strcpy(t,name[i]); strcpy(name[i],name[k]); strcpy(name[k],t);
   int tt=s[i]; s[i]=s[k]; s[k]=tt;
   }
  }
  for(int i=1;i<=tot;i++) printf("%s %d\n",name[i],s[i]);
  return 0;
}
/*
Sample Input
3
Spain Donna Elvira
England Jane Doe
Spain Donna Anna

Sample Output
England 1
Spain 2
*/

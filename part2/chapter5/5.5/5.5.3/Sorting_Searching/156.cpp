#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
char dict[1010][30],a[1010][30],b[1010][30];
int n,k; //n words, k Ananagrams
int cmp_chr(const void* a,const void* b)
{
  char* aa=(char*)a; char* bb=(char*)b;
  return *aa-*bb;
}
int cmp_str(const void* a,const void* b)
{
  char* aa=(char*)a; char* bb=(char*)b;
  return strcmp(aa,bb);
}
int main()
{
  char buf[30];
  n=k=0;
  for(;;)
  {
    scanf("%s",buf);
    if(buf[0]=='#') break;
    n++;
    strcpy(dict[n],buf);
    int l=strlen(buf);
    for(int i=0;i<l;i++) buf[i]=tolower(buf[i]);
    qsort(buf,l,sizeof(char),cmp_chr);
    strcpy(a[n],buf);
  }
  //for(int i=1;i<=n;i++) printf("%d.[%s] ",i,dict[i]); printf("\n");
  //for(int i=1;i<=n;i++) printf("%d.[%s] ",i,a[i]);
  for(int i=1;i<=n;i++)
  {
    bool flag=false;
    for(int j=1;j<=n;j++) if(i!=j)
     if(!strcmp(a[i],a[j])) {flag=true; break;}
    if(!flag) {k++;strcpy(b[k],dict[i]);}
  }
  qsort(b+1,k,sizeof(b[0]),cmp_str);
  for(int i=1;i<=k;i++) printf("%s\n",b[i]);
  return 0;
}
/*
Sample input

ladder came tape soon leader acme RIDE lone Dreis peat
 ScAlE orb  eye  Rides dealer  NotE derail LaCeS  drIed
noel dire Disk mace Rob dries
#

Sample output

Disk
NotE
derail
drIed
eye
ladder
soon
*/

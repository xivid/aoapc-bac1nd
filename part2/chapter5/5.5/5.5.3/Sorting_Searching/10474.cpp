#include<cstdio>
#include<cstdlib>
#include<cstring>
int n,q,a[10010];
int main()
{
  int cases=1;
  while(scanf("%d%d",&n,&q)==2)
  {
    if(n==0&&q==0) break;
    printf("CASE# %d:\n",cases++);
    memset(a,0,sizeof(a));
    int t,pos=0,max=-1,tot=0;
    for(int i=1;i<=n;i++)
    {
      scanf("%d",&t);
      a[t]++;
      if(t>max) max=t;
    }
    for(int i=1;i<=max;i++) if(a[i]) {tot=a[i]; a[i]=pos+1; pos+=tot; }
    for(int i=1;i<=q;i++)
    {
      scanf("%d",&t);
      if(a[t]) printf("%d found at %d\n",t,a[t]);
      else printf("%d not found\n",t);
    }
  }
  return 0;
}
/*
 Sample Input

4 1
2
3
5
1

5

5 2
1
3
3
3
1

2
3
0 0

Sample Output

CASE# 1:
5 found at 4
CASE# 2:
2 not found
3 found at 3

*/

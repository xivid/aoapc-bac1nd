#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int s[1010],g[1010],viss[1010],visg[1010],n;
int main()
{
  int cases=0;
  for(;;)
  {
    memset(s,0,sizeof(s));
    memset(g,0,sizeof(g));
    scanf("%d",&n);
    if(n==0) break;
    printf("Game %d:\n",++cases,n);
    for(int i=1;i<=n;i++) scanf("%d",&s[i]);
    for(;;)
    {
      int a=0,b=0;
      for(int i=1;i<=n;i++) scanf("%d",&g[i]);
      if(g[1]==0) break;
      memset(viss,0,sizeof(viss));
      memset(visg,0,sizeof(visg));
      for(int i=1;i<=n;i++) if(s[i]==g[i]) {a++; viss[i]=visg[i]=1;}

      for(int i=1;i<=n;i++)
       if(!visg[i])
        for(int j=1;j<=n;j++)
         if(s[j]==g[i]&&!viss[j]) {b++; viss[j]=visg[i]=1; break;}
        //优化思路：既然强相关的已经找出，那么剩下的若相关，必然为弱相关，可以将g剩下的元素排序，提高搜索效率
      printf("    (%d,%d)\n",a,b);
    }
  }
  return 0;
}

/*
Sample Input

4
1 3 5 5
1 1 2 3
4 3 3 5
6 5 5 1
6 1 3 5
1 3 5 5
0 0 0 0
10
1 2 2 2 4 5 6 6 6 9
1 2 3 4 5 6 7 8 9 1
1 1 2 2 3 3 4 4 5 5
1 2 1 3 1 5 1 6 1 9
1 2 2 5 5 5 6 6 6 7
0 0 0 0 0 0 0 0 0 0
0

Sample Output

Game 1:
    (1,1)
    (2,0)
    (1,2)
    (1,2)
    (4,0)
Game 2:
    (2,4)
    (3,2)
    (5,0)
    (7,0)
*/
/*
//网上的优秀解法：
#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,j,a[1001],b[1001],aa[10],bb[10],now=0;
    while (scanf("%d",&n)==1)
    {
          if (n==0) break;
          printf("Game %d:\n",++now);
          for (i=1;i<=n;i++) scanf("%d",&a[i]);
          while (true)
          {
                for (i=1;i<=n;i++) scanf("%d",&b[i]);
                if (b[1]==0) break;
                int x=0,y=0;
                memset(aa,0,sizeof(aa));
                memset(bb,0,sizeof(bb));
                for (i=1;i<=n;i++) if (a[i]==b[i]) x++; else {aa[a[i]]++;bb[b[i]]++;}
                for (i=1;i<=9;i++) if (aa[i]<bb[i]) y+=aa[i]; else y+=bb[i]; //取交集，手工模拟一下即可理解
                printf("    (%d,%d)\n",x,y);
          }
    }
    return 0;
}

#include<cstdio>
#include<cstdlib>
#include<cstring>
#define maxn 100 + 10
#define set0(a) memset(a, 0, sizeof(a))
int g[maxn][maxn], n, ne[maxn], min, vis[maxn], ans[maxn], best[maxn];
void dfs(int cur, int found){
  if(cur == n+1){
    if(found < min){
     min = found;
     for(int i=1; i<=n; i++) best[i] = ans[i];
    }
  }
  else{
   for(int i=1; i<=n; i++) if(!vis[i]){
    int max=0, linked=0;
    for(int j=1; j<cur; j++) if(g[i][ans[j]]){
      linked++;
      if(cur-j>max) max = cur-j;
    }
    //printf("cur=%d,i=%d,max=%d,min=%d,ne[i]=%d,linked=%d\n",cur,i,max,min,ne[i],linked);
    if(max<min&&((ne[i]-linked<min)||(i==1))) {
      vis[i] = 1;
      ans[cur] = i;
      //printf("inserted %d\n", ans[cur]);
      //for(int j=1; j<=n; j++) printf("%d ",ans[j]); putchar('\n');
      if(max>found) found = max;
      dfs(cur+1, found);
      vis[i] = 0;
      ans[cur] = 0;
      //printf("%d backtrace,found=%d,min=%d\n",cur,found,min);
    }
   }
  }
}
int main()
{
  scanf("%d",&n);
  set0(g);
  set0(ne);
  set0(vis);
  set0(ans);
  min = n;
  for(int i=1; i<=n; i++)
    for(int j=1; j<=n; j++){
      scanf("%d",&g[i][j]);
      ne[i]++;
    }
  dfs(1,0);
  for(int i=1; i<=n; i++) printf("%d ",best[i]);
  printf("\n%d\n",min);
  return 0;
}
/*
5
0 1 1 0 1
1 0 0 1 1
1 0 0 1 0
0 1 1 0 1
1 1 0 1 0


8
0 1 0 0 0 1 0 0
1 0 1 0 0 0 1 1
0 1 0 1 0 0 0 1
0 0 1 0 1 0 1 1
0 0 0 1 0 1 1 0
1 0 0 0 1 0 1 0
0 1 0 1 1 1 0 1
0 1 1 1 0 0 1 0


8
0 0 1 1 1 1 0 0
0 0 0 1 0 0 0 1
1 0 0 1 1 0 1 1
1 1 1 0 0 1 0 0
1 0 1 0 0 1 1 0
1 0 0 1 1 0 0 0
0 0 1 0 1 0 0 1
0 1 1 0 0 0 1 0
*/

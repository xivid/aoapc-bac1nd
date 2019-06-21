#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<stack>
#define maxn 100
int g[maxn][maxn],d[maxn];
int vis[maxn][maxn],n,m;
void dfs(int u) //不能形成回路的边根本走不到循环体之内（12~14行）
{
 for(int i=1;i<=n;i++) if(g[u][i]&&!vis[u][i]) //找每个与u邻接的点，找到能走成回路的才输出
 {
  vis[u][i]=vis[i][u]=1;
  dfs(i);
  printf("%d %d\n",u,i);  //不能将dfs 放在 printf之后，以免输出不能形成回路的边
 }
}
int main(){
 int u,v;
 memset(g,0,sizeof(g));
 memset(vis,0,sizeof(vis));
 memset(d,0,sizeof(d));
 scanf("%d%d",&n,&m); //n nodes,m edges
 for(int i=1;i<=m;i++){
  scanf("%d%d",&u,&v);
  g[u][v]=g[v][u]=1;
  d[u]++; d[v]++;
 }
 /* //procedure print_graph
 for(int i=1;i<=n;i++){
  for(int j=1;j<=n;j++) printf("%d",g[i][j]);
  printf("\n");
 }
 */
 int j=0,start=1;
 for(int i=1;i<=n;i++) if(d[i]%2) {j++; start=i;}
 if(j!=0&&j!=2) printf("j=%d,No euler path!\n",j);
 else dfs(start);
 return 0;
}
/*
5 5
1 2
2 3
3 4
4 5
5 1
*/
/*
7 10
1 2
1 3
1 6
2 3
3 4
4 5
4 6
4 7
5 6
6 7
//可用此例测试dfs与printf次序先后对答案的影响
*/
/*
4 7
1 2
1 2
2 3
2 3
2 4
1 4
3 4
*/

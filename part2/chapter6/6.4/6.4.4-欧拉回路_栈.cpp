#include<cstdio>
#include<cstdlib>
#define maxn 100
int n,m; //node 1~n
int g[maxn][maxn],vis[maxn][maxn];
int d[maxn]={0}; //统计每个点的度
int su[maxn],sv[maxn],top=0;
void euler(int u)
{
 for(int v=1;v<=n;v++) if(g[u][v]&&!vis[u][v]){
  vis[u][v]=vis[v][u]=1; //有向图只需改为vis[u][v]=1
  euler(v);
  top++;
  su[top]=u; sv[top]=v;
 }
}
int main()
{
 int u,v;
 scanf("%d%d",&n,&m);
 for(int i=0;i<m;i++)
 {
  scanf("%d%d",&u,&v);
  g[u][v]=g[v][u]=1;  //有向图只需改为g[u][v]=1
  d[u]++; d[v]++;
 }
 int j=0,start=1;
 for(int i=1;i<=n;i++) if(d[i]%2) {j++; start=i;}
 if(j!=0&&j!=2) printf("No euler path!\n");
 else {
  euler(start);
  while(top) {printf("%d-%d ",su[top],sv[top]); top--;}
 }
 return 0;
}

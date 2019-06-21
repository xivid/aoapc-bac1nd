#include<cstdio>
#include<cstring>
const int maxn = 1000;
const int INF = 0x7f7f7f7f;
int n, m;
int G[maxn][maxn];
int dist[maxn], vis[maxn];
int prim(int v0){
  memset(vis, 0, sizeof(vis));
  int ans = 0;
  for(int i = 1; i <= n; ++i) dist[i] = G[v0][i];
  vis[v0] = 1;
  for(int t = 1; t < n; ++t){
    int min = INF, k = 0;
    for(int i = 1; i <= n; ++i) if(!vis[i] && min > dist[i]){
      min = dist[i]; k = i;
    }
    vis[k] = 1;
    ans += min;
    if(!k) break;
    for(int i = 1; i <= n; ++i) if(!vis[i] && G[k][i] < dist[i]) dist[i] = G[k][i];
  }  
  return ans;
}  
int main(){
  scanf("%d%d", &n, &m);
  int u, v, w;
  memset(G, 60, sizeof(G));
  for(int i = 1;i <=m ;++i) {
    scanf("%d%d%d", &u, &v, &w);
    G[u][v] = G[v][u] = w;
  }
  printf("%d\n", prim(1));  
  while(1);
  return 0;
}  
/*
5 7
1 2 5
1 3 1
1 4 2
1 5 4
2 4 1
3 4 5
3 5 2
*/

#include<cstdio>
#include<cstring>
const int maxn = 1000;
int n, m;
int G[maxn][maxn];
int dist[maxn], vis[maxn];
const int INF = 0x7f7f7f7f;
int Prim(int v0){
  for(int i = 1; i <= n; ++i) dist[i] = G[v0][i];
  vis[v0] = 1;
  int ans = 0;
  for(int i = 1; i < n; ++i){
    int min = INF, k = 0;
    for(int j = 1; j <= n; ++j) if(!vis[j] && dist[j] < min){
      min = dist[j]; k = j;
    }
    if(!k) break; 
    vis[k] = 1, ans += min;
    for(int j = 1; j <= n; ++j) if(!vis[j] && G[k][j] < dist[j]) dist[j] = G[k][j];  
  }  
  return ans;
}  
int main(){
  scanf("%d%d", &n, &m);
  int u, v, w;
  memset(G, INF, sizeof(G));
  //for(int i = 1; i <= n; ++i) G[i][i] = 0;
  for(int i = 1; i <= m; ++i) {
    scanf("%d%d%d", &u, &v, &w);
    G[u][v] = G[v][u] = w;
  }
  printf("%d\n", Prim(1));
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
   

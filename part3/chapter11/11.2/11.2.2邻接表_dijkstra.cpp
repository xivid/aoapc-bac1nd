#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 1005, maxm = 100005;
int first[maxn];
int w[maxm], u[maxm], v[maxm], next[maxm];
int n, m, dist[maxn], vis[maxn];
const int INF = 0x7f7f7f7f;
void read_graph(){
  scanf("%d%d", &n, &m);
  memset(first, -1, sizeof(first));
  /*for(int e = 1; e <= m; e++){
    scanf("%d%d%d", u+e, v+e, w+e);
    next[e] = first[u[e]];
    first[u[e]] = e;
  }*/
  /*
  for(int e = 1; e <= m; ++e){
    scanf("%d%d%d", &u[2*e-1], &v[2*e-1], &w[2*e-1]);
    next[2*e-1] = first[u[2*e-1]];
    first[u[2*e-1]] = 2*e-1;
    u[2*e] = v[2*e-1], v[2*e] = u[2*e-1], w[2*e] = w[2*e-1];
    next[2*e] = first[u[2*e]];
    first[u[2*e]] = 2*e;
  } 
  */
  
  for(int e = 1; e < 2*m; e+=2){
    scanf("%d%d%d", u+e, v+e, w+e);
    next[e] = first[u[e]];
    first[u[e]] = e;
    u[e+1] = v[e];
    v[e+1] = u[e];
    w[e+1] = w[e];
    next[e+1] = first[u[e+1]];
    first[u[e+1]] = e+1;
  }  
}    
int main(){
  freopen("1.in", "r", stdin);
  read_graph();
  
  int source = 1;
  memset(dist, INF, sizeof(dist));
  memset(vis, 0, sizeof(vis));
  dist[source] = 0;
  for(int i = 1; i <= n; ++i){
    int m = INF, x;
    for(int y = 1; y <= n; ++y) if(!vis[y] && dist[y] < m) m = dist[x = y];
    vis[x] = 1;
    for(int e = first[x]; e != -1; e = next[e]) dist[v[e]] = min(dist[v[e]], w[e] + m);
  }
  for(int i = 1; i <= n; ++i) printf("dist[%d] = %d\n", i, dist[i]);
  for(;;);
  return 0;
}    
  

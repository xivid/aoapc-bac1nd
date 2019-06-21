#include<cstdio>
#include<cstring>
#include<cstdlib>
const int INF = 0x7f7f7f7f;
int n, m;
const int maxn = 1010, maxm =  10010;
int next[maxm], first[maxn], dist[maxn];
int u[maxm], v[maxm], w[maxm];
int main(){
  freopen("1.in", "r", stdin);
  scanf("%d%d", &n, &m);
  for(int i = 1; i <= m; ++i) {
    scanf("%d%d%d", u+i, v+i, w+i);
    next[i] = first[u[i]];
    first[u[i]] = i;
  }
  memset(dist, INF, sizeof(dist));
  int source;
  dist[source = 1] = 0;
  for(int k = 1; k < n; ++k)
    for(int i = 1; i <= m; ++i){
      int x = u[i], y = v[i];
      if(dist[x]<INF && dist[x] + w[i] < dist[y]) dist[y] = dist[x] + w[i];
    }
  for(int i = 1; i <= m; ++i){
      int x = u[i], y = v[i];
      if(dist[x]<INF && dist[x] + w[i] < dist[y]) {puts("Negative acyclic graph"); break;}
    }  
  for(int i =1; i <= n; ++i) printf("dist[%d] = %d\n", i, dist[i])  ;
  while(1);
  return 0;
}  

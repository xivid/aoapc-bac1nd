#include<cstdio>
#include<bitset>
#include<algorithm>
#include<stack>
#include<utility>
using namespace std;
const int maxn = 1005;
int n, m;
int g[maxn][maxn], dist[maxn], fa[maxn];
bitset<maxn> vis;
const int INF = 0x7f7f7f7f;
int main(){
  freopen("1.in", "r", stdin);
  int u, v, w;
  scanf("%d%d", &n, &m);
  memset(g, INF, sizeof(g));
  for(int i = 1; i <= m; ++i){
    scanf("%d%d%d", &u, &v, &w);
    g[u][v] = w; //DAG
    //g[u][v] = g[v][u] = w;
  }  
  
  int source = 1;
  fa[source] = source;
  memset(dist, INF, sizeof(dist));
  dist[source] = 0;
  vis.reset();
  for(int i = 1; i <= n; ++i){
    int m = INF, x;
    for(int y = 1; y <= n; ++y) if(!vis[y] && dist[y] <= m) m = dist[x = y];
    vis[x] = 1;
    for(int y = 1; y <= n; ++y) if(m + g[x][y] < dist[y]){
      dist[y] = m + g[x][y];
      fa[y] = x;
    }  
  }
  for(int i = 1; i <= n; ++i)  printf("dist[%d] = %d\n", i, dist[i]);
  
  //print_path1(n);
  typedef pair<int, int> pii;
  stack<pii> s1;
  int dest = n;
  while(dest != source){
    for(int i = 1; i <= n; ++i) if(dist[i] + g[i][dest] == dist[dest]){
      s1.push(make_pair(i, g[i][dest]));
      dest = i;
      break;
    }  
  }  
  while(!s1.empty()) {printf("%d---(%d)--->", s1.top().first, s1.top().second); s1.pop();}
  printf("%d\n", n);
  
  //print_path2(n);
  stack<pii> s2;
  dest = n;
  while(fa[dest] != dest){
    s2.push(make_pair(fa[dest], g[fa[dest]][dest]));
    dest = fa[dest];
  }  
  while(!s2.empty()) printf("%d---(%d)--->", s2.top().first, s2.top().second),s2.pop();
  printf("%d\n", n);
  while(1);
  return 0;
}  

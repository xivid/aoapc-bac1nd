#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int maxn = 1010, maxm = 10010;
int u[maxm], v[maxm], w[maxm];
int n, m, dist[maxn], next[maxm], first[maxn];
const int INF = 0x7f7f7f7f;
void read_graph(){
  freopen("1.in", "r", stdin);
  scanf("%d%d", &n, &m);
  memset(first, -1, sizeof(first));
  for(int i = 1; i <= m; ++i) {
    scanf("%d%d%d", u+i, v+i, w+i);
    next[i] = first[u[i]];
    first[u[i]] = i;
  }
} 
typedef pair<int, int> pii;
priority_queue<pii ,vector<pii>, greater<pii> > q;
int main(){
  read_graph();
  int source = 1;
  memset(dist, INF, sizeof(dist));
  dist[source] = 0;
  q.push(make_pair(dist[source], source));
  while(!q.empty()){
    pii u = q.top(); q.pop();
    int x = u.second;
    if(u.first != dist[x]) continue;
    for(int e = first[x]; e != -1; e = next[e]) if(dist[v[e]] > dist[x] + w[e]){
      dist[v[e]] = dist[x] + w[e];
      q.push(make_pair(dist[v[e]], v[e]));
    }  
  }  
  for(int i = 1; i <= n; ++i) printf("dist[%d] = %d\n", i, dist[i]);
  while(1);
  return 0;
}  

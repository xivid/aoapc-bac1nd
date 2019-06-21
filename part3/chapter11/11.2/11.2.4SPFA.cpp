#include<cstdio>
#include<cstring> 
#include<queue>
#include<bitset>
using namespace std;
const int INF = 0x7f7f7f7f;
const int maxn = 1010 , maxm = 10010;
int u[maxm], v[maxm], w[maxm], first[maxn], next[maxm], dist[maxn];
int n, m;
bitset<maxn> inq;
queue<int> q; 
int main(){
  freopen("1.in", "r", stdin);
  scanf("%d%d", &n, &m);
  memset(next, -1, sizeof(next));
  for(int i = 1; i <= m; ++i) {
    scanf("%d%d%d", u+i, v+i, w+i);
    next[i] = first[u[i]];
    first[u[i]] = i;
  }
  int source = 1;
  memset(dist, INF, sizeof(dist));
  dist[source] = 0;
  inq.reset();
  q.push(source);
  inq[source] = 1;
  while(!q.empty()){
    int x = q.front(); q.pop();
    inq[x] = 0; 
    for(int e = first[x]; e != -1; e = next[e]) if(dist[v[e]] > dist[x] + w[e]){
      dist[v[e]] = dist[x] + w[e];
      if(!inq[v[e]]){
        inq[v[e]] = 1;
        q.push(v[e]);
      }
    }
  }      
  for(int i = 1; i <= n; ++i) printf("dist[%d] = %d\n", i, dist[i]);
  while(1);
  return 0;
}  

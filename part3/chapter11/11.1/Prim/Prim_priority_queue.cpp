#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <bitset>
using namespace std;
const int INF = 0x7f7f7f7f;
const int maxn = 1010, maxm = 10010;
int u[maxm], v[maxm], w[maxm], next[maxm];
int n, m, dist[maxn], first[maxn];
typedef pair<int, int> pii;
priority_queue<pii, vector<pii>, greater<pii> > q;

bitset<maxn> vis;
int prim(){
  int ans = 0;
  memset(dist, INF, sizeof(dist));
  dist[1] = 0;
  q.push( make_pair( dist[1], 1) );
  vis.reset();
  while(!q.empty()){
    int x = q.top().second; q.pop();
    if(vis[x]) continue;
    vis[x] = 1; ans += dist[x];
    for(int e = first[x]; e != -1; e = next[e]) if(!vis[v[e]] && dist[v[e]] > w[e]){
      dist[v[e]] = w[e];
      q.push( make_pair(w[e], v[e]) );
    }
  }return ans;
}    
      
  
int main(){
  scanf("%d%d", &n, &m);
  memset(first, -1, sizeof(first));
  for(int e = 1; e <= m; ++e){
    scanf("%d%d%d", &u[2*e-1], &v[2*e-1], &w[2*e-1]);
    next[2*e-1] = first[u[2*e-1]];
    first[u[2*e-1]] = 2*e-1;
    u[2*e] = v[2*e-1], v[2*e] = u[2*e-1], w[2*e] = w[2*e-1];
    next[2*e] = first[u[2*e]];
    first[u[2*e]] = 2*e;
  } 
  printf("%d\n", prim());
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
(6)
5 7
1 5 6
2 5 7
2 4 7
2 3 9
1 4 5
1 2 4
3 4 2
(17)

typedef pair<int, int> pii;
bitset<maxn> vis;
priority_queue<pii, vector<pii>, greater<pii> >q;
int prim(){
  int ans = 0;
  vis.reset();
  memset(dist, INF, sizeof(dist));
  dist[1] = 0;
  q.push( make_pair(dist[1], 1) );
  while(!q.empty()){
    pii x = q.top(); q.pop();
    int y = x.second;
    if(vis[y]) continue;
    vis[y] = 1;
    ans += x.first;
    for(int e = first[y]; e != -1; e = next[e]) if(!vis[v[e]] && dist[v[e]] > w[e]){
      dist[v[e]] = w[e];
      q.push( make_pair(dist[v[e]], v[e]) );
    }  
  }
  return ans;
}    
*/ 
